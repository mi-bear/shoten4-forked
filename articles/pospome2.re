# 続・新しく型を定義することによって可能になる実装パターン
## はじめに
メルカリのサーバサイドエンジニア pospome です。
普段は GCP + Go でサーバサイドの開発をしています。

前回の GopherWalker では、
`新しく型を定義することによって可能になる実装パターン` というタイトルで、
主に int, string などの `値を表現する型` に type を用いる実装パターンを紹介しました。

今回はその続編ということで、
func に type を用いる実装パターンを紹介します。

前回の内容と重複する部分もありますが、
func という `処理` に対して type を用いる場合、
int, string のような `値` とは違った性質を持つ実装パターンになります。

## func は値である
golang では、func を値として扱うことができます。
以下は func である EchoName() を値として変数eに代入し、実行する例です。
```
package main

import "fmt"

func main() {
	e := EchoName
	e() //pospome
}

func EchoName() {
	fmt.Println("pospome")
}
```

func は値なので、引数、戻り値に指定することが可能です。
```
package main

import "fmt"

func main() {
	f := Do(EchoName)
	f() //pospome
}

func EchoName() {
	fmt.Println("pospome")
}

func Do(f func()) func() {
	return f
}
```

引数に func を指定する実装はとても便利で、
以下のように特定の func を外部から注入し、
任意の処理を実行させることができます。
```
package main

import "fmt"

func main() {
	f1 := EchoName

	//無名関数として定義することもできる。
	f2 := func() {
		fmt.Print("not pospome")
	}

	Do(f1) //logic1,pospome,logic2
	Do(f2) //logic1,not pospome,logic2
}

func EchoName() {
	fmt.Print("pospome")
}

func Do(f func()) {
	fmt.Print("logic1,")
	f()
	fmt.Println(",logic2")
}
```

## func に型を定義するとは?
func は値なので型を定義できます。

具体的には以下のように定義することができます。
```
type MyEchoName func()
```

以下のように func に引数と戻り値を指定することも可能です。
```
type MyEchoName func(id int) (int, error)
```

## func を type として定義した際にできるようになること
func に type を定義することによって、
次のようなことができるようになります。

* キャスト
* メソッド定義
* インターフェース実装

### キャスト
型を満たす func をキャストすることができます。

以下の例では EchoName() を func() から MyEchoName へキャストしています。
型が func() から MyEchoName へ変わっただけで挙動に変化はありません。
```
package main

import "fmt"

func main() {
	e := EchoName
	m := MyEchoName(e)
	m() //pospome
}

type MyEchoName func()

func EchoName() {
	fmt.Println("pospome")
}
```

### メソッド定義
func に type を用いることでメソッドを定義することができます。
以下は MyEchoName に DoSomething() というメソッドを定義してます。
```
package main

import "fmt"

func main() {
	e := EchoName
	m := MyEchoName(e)
	m.DoSomething() //DoSomething
}

type MyEchoName func()

func (e MyEchoName) DoSomething() {
	fmt.Print("DoSomething")
}

func EchoName() {
	fmt.Print("pospome")
}
```

func にメソッドを定義できるのって何か不思議だなーと思うのは、私だけでしょうか・・・?

### インターフェース実装
メソッドを定義できるのであれば、当然インターフェースを満たすことができます。
以下は MyEchoName が XxxInterface を満たしている実装です。
```
package main

import "fmt"

func main() {
	e := EchoName
	m := MyEchoName(e)
	Do(m)
}

type XxxInterface interface {
	Xxx()
}

type MyEchoName func()

func (e MyEchoName) Xxx() {
	fmt.Print("Xxx")
}

func EchoName() {
	fmt.Print("pospome")
}

func Do(x XxxInterface) {
	x.Xxx()
}
```

## 実装パターン
### 引数を型で明示する
仕様が複雑なWebサービスのアプリケーションコードにおいて、
`一部だけ処理の流れが違う` というケースはよくあるのではないでしょうか?
```
func Do() {
	//前半の処理は常に同じ

	//途中の処理だけ常に同じとは限らない

	//後半の処理も常に同じ
}
```

この場合、以下のように if を利用して解決することができます。
```
func Do() {
	//前半の処理は常に同じ

	//途中の処理だけ常に同じとは限らない
	if xxx {
		//省略
	} else {
		//省略
	}

	//後半の処理も常に同じ
}
```

しかし、以下のケースでは引数に func を指定して解決することが多いと思います。
* if の分岐パターンが予想できない場合 
* Do() の内部で分岐処理を書くと見通しが悪くなる場合
* インターフェースで表現すると不自然になる場合
```
func Do(f func()) {
	//前半の処理は常に同じ

	//途中の処理だけ常に同じとは限らない
	f()

	//後半の処理も常に同じ
}
```

func の定義方法は複数存在します。

以下のように無名関数として func を定義する方法です。
```
package main

import "fmt"

func main() {
	//無名関数として定義する
	f := func() {
		fmt.Println("pospome")
	}
	Do(f)
}

func Do(f func()) {
	//前半の処理はいつも同じ

	//途中の処理だけ常に同じとは限らない
	f()

	//後半の処理もいつも同じ
}
```

このコードには以下の問題があります。

* 具体的に何の処理なのかが分かりづらい
無名関数は文字通り `無名` なので、
具体的に何の処理なのかを明示することができません。
あくまで処理内容がコードとして記載されているだけです。

これは無名関数を通常の関数として定義することで解決することができます。
以下は無名関数の実装を EchoName() として定義しています。
```
package main

import "fmt"

func main() {
	e := EchoName
	Do(e)
}

func Do(f func()) {
	//前半の処理はいつも同じ

	//途中の処理だけ同じとは限らないので引数で渡される f を利用する
	f()

	//後半の処理もいつも同じ
}

//関数名で具体的な処理を表現できる。
//他の箇所で使い回すことができる。
func EchoName() {
	fmt.Println("pospome")
}
```

ちなみに、無名関数内の処理が単純で自明なものであれば、
無名関数として定義しても問題ありません。
単純で自明なものであるかどうかの基準はしっかりと考える必要があります。

これで解決したように見えますが、まだ1つだけ問題が残っています。

それは、`引数に何を指定するか分かりづらい` という点です。
以下の Do() の引数は func() です。
```
func Do(f func()) {
	//前半の処理はいつも同じ

	//途中の処理だけ同じとは限らないので引数で渡される f を利用する
	f()

	//後半の処理もいつも同じ
}
```

func() には具体的には何を指定すればいいのでしょうか?
どこかに定義されている関数を指定するのでしょうか?
それとも、無名関数で実装するのでしょうか?

もし、どこかに定義されている関数を指定する場合、
それはどの関数なのでしょうか?

この問題は func に type を用いることで解決することができます。

以下は Do() の引数を func() から EchoName に変更した実装です。
```
package main

import "fmt"

func main() {
	p := NewEchoPospome()
	Do(p)
}

func Do(e EchoName) {
	//前半の処理はいつも同じ

	//途中の処理だけ同じとは限らないので引数で渡される f を利用する
	e()

	//後半の処理もいつも同じ
}

type EchoName func()

//pospome用の実装
func NewEchoPospome() EchoName {
	f := func() {
		fmt.Println("pospome")
	}
	return EchoName(f)
}

//他の人用の実装
func NewEchoSomebody() EchoName {
	f := func() {
		fmt.Println("somebody")
	}
	return EchoName(f)
}
```

EchoName を定義し、
それを生成する NewEchoPospome(), NewEchoSomebody() を実装することで以下が明示的に表現できます。

* Do() に指定する引数が EchoName であること
* EchoName には Pospome実装とSomebody実装の2つのみ提供されていること
* 提供されている実装以外の実装が必要な場合、新規実装しなければいけないこと

今回の例は Do(), EchoName のように比較的抽象的だったので、
あまりイメージできないかもしれませんが、
以下のように具体的なロジックを表現する場合、単なる func() という定義よりも分かりやすくなるでしょう。
```
type UserScoreLogic func(userScore int) (totalScore int)

func NewNormalUserLogic() UserScoreLogic {
	//省略
}

func NewSpecialUserLogic() UserScoreLogic {
	//省略
}

//ユーザーの score 算出ロジックを切り替えられることが分かる。
func Do(f UserScoreLogic) {

}
```

### ロジックの差し替え
本節で紹介する `ロジックの差し替え` は、
func そのものの性質を利用した実装パターンです。

func に type を用いることによる実装パターンではないのですが、
この機会に紹介させていただきます。

前節でも言及したように、
func はそれ自体がgolangにおけるプリミティブな定義なので、
func を引数に指定することによって任意の処理を実行させることができます。

例えば、以下の実装の場合、
Do() の引数である DoFunc を満たす値を渡すことで、任意の処理を実行させることができます。
```
package main

import "fmt"

func main() {
	Do(NewHelloFunc())
}

func Do(f DoFunc) {
	f()
}

type DoFunc func()

func NewHelloFunc() DoFunc {
	f := func(){
		fmt.Println("hello")
	}
	return DoFunc(f)
}
```

こういった `処理の差し替え` は、インターフェースを利用することでも実現できます。
以下は struct + インターフェースの組み合わせの例です。
```
package main

import "fmt"

func main() {
	h := &Hello{}
	Do(h)
}

func Do(f DoFunction) {
	f.Exec()
}

type DoFunction interface {
	Exec()
}

//フィールドを持たない struct になる
type Hello struct {
}

func (h *Hello) Exec() {
	fmt.Println("hello")
}
```

上記の実装で気になるのは、Hello struct がフィールドを持たない点です。

インターフェースを利用することで、処理を差し替えることはできていますが、
値を持たない struct に意味はあるのでしょうか?

インターフェースは type に対する抽象的な振る舞いを定義します。
さきほどの空の struct のように type の定義そのものが不自然であれば、
インターフェースを実装させることも不自然です。

`処理の差し替え` が本質的な目的である場合、
func を差し替えることで実現させた方が自然な設計になるはずです。
空の struct にインターフェースを実装する際は一度立ち止まって考えてみましょう。

ちなみに、インターフェースには `複数の振る舞いを定義できる` という仕様がありますが、
func は値なので、複数定義することはできません。
```
type DBFunc interface {
	Begin()
	Commit()
	Rollback()
}
```

これは以下のように func を束ねる struct を用意することで解決できます。
```
type DBFunc struct {
	Begin Begin
	Commit Commit
	Rollback Rollback
}

type Begin func()
type Commit func()
type Rollback func()
```

複数の func を struct で定義する場合は、
上記の Begin, Commit, Rollback のように明示的に type を定義すると、
struct との関連性が分かりやすくなります。

### インターフェースを提供することによる実装選択肢の確保
前節では `処理の差し替え` を func によって実現するという例を紹介しました。
しかし、func によって `処理の差し替え` を実現し、さらにインターフェースも定義するケースが存在します。

以下は前節で紹介した例です。
```
package main

import "fmt"

func main() {
	Do(NewHelloFunc())
}

func Do(f DoFunc) {
	f()
}

type DoFunc func()

func NewHelloFunc() DoFunc {
	return func(){
		fmt.Println("hello")
	}
}
```

一見問題ないように見えますが、
コードは時と共に要件が変化していくものです。

1年後、Do() の引数に struct を指定したくなる可能性もあります。
その際、既存の DoFunc を利用しているコードに影響を与えることは避けたいでしょう。

この問題はインターフェースを定義することで解決できます。

具体的には、
Do() の引数に func ではなく、 DoInterface を指定するように修正します。
そして、 DoFunc には DoInterface.Call() を実装します。
DoFunc.Call() は DoFunc をそのまま実行するだけです。
```
package main

import "fmt"

func main() {
	//ここのコードは修正不要
	Do(NewHelloFunc())
}

//引数を DoInterface に変更
func Do(d DoInterface) {
	d.Call()
}

type DoInterface interface {
	Call()
}

type DoFunc func()

// DoFunc を実行するだけのメソッド
func (d DoFunc) Call() {
	d()
}

//ここの戻り値は DoFunc のままでOK
func NewHelloFunc() DoFunc {
	f := func(){
		fmt.Println("hello")
	}
	return DoFunc(f)
}
```

Do() の引数をインターフェースにすることで、
以下のような struct を引数に渡すことが可能になります。
```
type DoStruct {
	X, Y int
}

func (d DoStruct) Call() {
	fmt.Println(d.X)
	fmt.Println(d.Y)
}
```

この例を見る限り、インターフェースは便利なので、全てインターフェースにした方がいいのでは? と思うかもしれませんが、
そうとも限りません。

インターフェースは `抽象的な振る舞い` を定義するものです。

抽象的な振る舞いではないものをインターフェースにしてしまうと、
実装対象の仕様とコードにミスマッチが生まれてしまい、
コードから伝わる意図が間違ったものになってしまいます。
可能な限り、 `抽象的な振る舞い` にのみインターフェースを適用させましょう。

反面、不特定多数が利用するライブラリ、フレームワークなどは、
利用者のニーズを絞り込むことが難しいことが多いです。
利用者によっては、その振る舞いが抽象的なものになるかもしれません。
こういった利用者のニーズに幅広く対応するために、最初からインターフェースを提供する場合があります。

### メソッドを利用した特定処理の差し込み
func に type を用いることによって、メソッドを定義することができます。
```
type Xxx func()

func (x Xxx) Do {
}
```

レシーバは func なので、以下のように func を実行する前後に特定の処理を差し込むことが可能です。
以下は引数 userScore に対するバリデーションをメソッドによって実装した例です。
```
package main

import "fmt"

func main() {
	userScore := 100

	c := NewTotalCalcScore()

	fmt.Println(c(userScore)) //100
	fmt.Println(c.WithValidation(userScore))//100

	userScore = 0
	fmt.Println(c.WithValidation(userScore))//panic: score = 0
}

type CalcTotalScore func(userScore int) (totalScore int)

func NewTotalCalcScore() CalcTotalScore {
	f := func(userScore int) (totalScore int) {
		//計算ロジックが実装されている想定
		return userScore
	}
	return CalcTotalScore(f)
}

func (c CalcTotalScore) WithValidation(userScore int) (totalScore int) {
	if userScore == 0 {
		panic("score = 0")
	}
	return c(userScore)
}
```

上記の例では、CalcTotalScore = `スコア計算` がメインの目的であり、
それに対するオプションとして WithValidation() が提供されています。

実際にこのようなバリデーションが適切な実装かどうかは判断しかねますが、
メソッドによって処理を差し込むイメージは理解できたはずです。

アプリケーションコードでは特定の処理をベースに複数の挙動が想定されているケースが存在します。
そのようなケースでは、こういった実装を上手く活用できる可能性があります。

## おわりに
本章では次の実装パターンを紹介しました。

 * 引数を型で明示する
 * ロジックの差し替え
 * インターフェースを提供することによる実装選択肢の確保
 * メソッドを利用した特定処理の差し込み

頭の片隅にしまっておくと、いつか役に立つかも知れませんね。
