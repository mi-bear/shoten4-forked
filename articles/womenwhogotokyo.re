= Women Who Go TokyoはGopherを待っています
== 1. Women Who Goとわたしたちのこれまでの活動について
こんにちは。Women Who Go Tokyoの運営スタッフの@akane_256@<fn>{akane_256_fn1}です。
普段は表参道のIT企業で、Webサイトの開発・運用に携わっています。
Women Who Goというコミュニティの歴史とわたしたちのこれまでの活動についてご紹介します。

//footnote[akane_256_fn1][@<href>{https://twitter.com/akane_256}]

=== Women Who Goとは？
Women Who Goは、2014年にサンフランシスコで、女性・ジェンダーマイノリティの方のためのGo言語のグローバルコミュニティとして設立されました。12カ国27都市で運営されています。(2018/4現在)
Women Who Goの活動の目的は、多くの女性やジェンダーマイノリティの方がGoのコミュニティに参加できるようにすることです。技術者のコミュニティは、最初は一人だと参加しづらいという声がしばしば聞かれますが、Women Who Goでは、その場で仲間を見つけることができる機会を提供したいと考えています。また、一人だとどうすれば良いかわからないことを質問しあうなど、協力しあいながら楽しくGoについて学んでいきます。
Women Who Goとして実施する活動の内容は、各国で自由で、ベルリンでは「Go In Action」の著者を招いてワークショップを行ったり、シカゴではGoの新バージョンがリリースされた際にリリースパーティを行ったりしています。そして、そのイベントの多くは無料で開催されています。

他国の活動については、@womenwhogo@<fn>{womenwhogo_fn1}のTwitterアカウントから見ることができます。

//footnote[womenwhogo_fn1][@<href>{https://twitter.com/womenwhogo}]

=== Women Who Go Tokyo(東京支部)の活動について
Women Who Go Tokyoは、2016年6月に日本で初めてのWomen Who Goのコミュニティとして設立されました。Goの情報が他の言語と比べて少なかったことと、上記の通り多くの女性やジェンダーマイノリティの方々と一緒に学んでいきたいという想いから、東京支部設立の運びとなり、私は立ち上げのスタッフの一人として参加をしました。
初めて2016年6月にイベントを実施して以降、毎月1回都内の会場に10人前後で集まり、Goについて学んでいます。内容は主に初学者向けのワークショップで、講師・メンターの方々を招いて自分で手を動かしながら進めていきます。
堅苦しい雰囲気ではなく、できるだけゆるく和やかに、気軽に参加できるような雰囲気にしたいと思い運営しています。そして、イベントは無料で開催をしています。
2016年にWomen Who Go Tokyoを設立をしてから、約2年間運営を続けてきました。今まで行ってきた活動を少しご紹介します。

==== 1. Goコントリビュータを講師に招いてワークショップ
2016年12月には、GoコントリビュータのDave Cheney氏を招いてワークショップを実施しました。Goの魅力や、基本構文など基礎の部分から、高度な構文やテストコードについて、1日かけて学びました。
日本語ではありませんが、Goを作っている方から直接プレゼンテーションを聞くことができました。
その際のスライドについては、こちらのURLからご覧いただけます。

https://talks.godoc.org/github.com/davecheney/introduction-to-go/introduction-to-go.slide#1@<fn>{introduction-to-go_fn1}

//footnote[introduction-to-go_fn1][@<href>{https://talks.godoc.org/github.com/davecheney/introduction-to-go/introduction-to-go.slide#1}]

==== 2. GCP Global Meetupの開催
2017年6月には、GCPUG Tokyo(Google Cloud Platform User Group)とイベントを共催しました。GDG Cloud Londonからは、女性エンジニアの@chibichibibr@<fn>{chibichibibr_fn1}が来日し、テクノロジー業界でのダイバーシティについてプレゼンテーションをしました。
Women Who Goも共催コミュニティとして、私が、GCP x Goをテーマに、Cloud Vision APIとGoを使って画像コンテンツ分析をするプレゼンテーションをしました。

//footnote[chibichibibr_fn1][@<href>{https://twitter.com/chibichibibr}]

==== 3. GDG Devfest Tokyoへの参加
2017年10月には、GDG Devfest Tokyo 2017に、初めてWomen Who Go Tokyoとして参加をしました。一緒にスタッフとして活動している@micchiebear@<fn>{micchiebear_fn1}さんと@mom0tomo@<fn>{mom0tomo_fn1}さんが、初めてGoを学んでからプロダクトに導入するまでの経験についてプレゼンテーションをしました。
その際のスライドについては、こちらのURLからご覧いただけます。

https://speakerdeck.com/mom0tomo/gotu-ran-ri-ji@<fn>{gotu-ran-ri-ji_fn1}

//footnote[gotu-ran-ri-ji_fn1][@<href>{https://speakerdeck.com/mom0tomo/gotu-ran-ri-ji}]

==== 4. プログラミング初学者向けのワークショップ
2018年は、プログラムを書いたことがない方、プログラミング歴の浅い方を対象にワークショップを行っています。プログラミングに興味があっても、自分一人で1から学習することはとても大変です。そういった方にも、気軽にきていただけるワークショップを開催しています。プログラミングの基本となる考え方や、Goの基本構文の学習をしています。
下記は、sliceと繰り返し文の練習で実際に書いたコードです。

//list[akane_list1][sliceと繰り返し文の練習]{
package main

func main() {
  var sum int
  slice := []int{20, 16, 5, 11}

  for i := 0; i < len(slice); i++ {
    sum += slice[i]
  }
  println(sum)
}
//}

Women Who Go Tokyoのその他の活動については、@wwg_tokyo@<fn>{wwg_tokyo_fn1}のTwitterアカウントをのぞいてみて下さい。もし少しでもご興味があれば、ぜひ気軽に足を運んでいただけるととても嬉しいです。

//footnote[wwg_tokyo_fn1][@<href>{https://twitter.com/wwg_tokyo}]

=== 東京以外の活動について
現在日本にあるWomen Who Goコミュニティは東京だけですが、東京以外でも支部を新設することができます。下記サイトのルールをもとに、Women Who Goの本部宛にご連絡ください。
不明点などあれば、わたしたちWomen Who Go Tokyoでもサポートいたします。
https://github.com/womenwhogo/wikis/blob/master/starting-a-chapter.md

== 2. はじめてのGo
Women Who Go Tokyoの@micchiebear@<fn>{micchiebear_fn1}です。
普段のシゴトは、株式会社リブセンスでJavaScript, node.jsを使うことが多いのですが、ちょいちょいGoを織り交ぜるようと暗躍しています。

//footnote[micchiebear_fn1][@<href>{https://twitter.com/micchiebear}]

Women Who Go TokyoはGoに興味がある女性とジェンダーマイノリティの方のためのコミュニティで、Goを書くのがはじめて！という方でも気楽に来ていただけるような会を目指しています。
よって本章では、はじめてGoを学ぶヒトに向けたパッションを書き綴っていきます。

=== Goの魅力ってなんだろう？
プログラミングの初学者であればあるほど、Goの魅力が輝きます。
Goの輝き:

 * 文法の正解パターンが少ないので迷いにくい。
 * Go本体はGoで書かれているので、Go本体がリファレンスになっている。そして読みやすい。
 * @<code>{gofmt}, @<code>{golint}, @<code>{goimportst}, @<code>{go vet}といった標準のツールがあり、Goの正解に自然と導いてくれる。
 * 標準ライブラリが必要最低限揃っているので、多くのモジュールがいつの間にか読み込まれているといったことが少ない。
 * マルチプラットフォーム！
 * 後述の@<code>{Playground}最高。

そして、キャラクターのGopherの~~キモ~~かわいらしさも魅力のひとつです。

=== Goの演習
@<code>{Playground}を利用することで、すぐにGoを書いて試すことができます。
難しい環境設定は必要ありません。
アクセスしたばかりのときは、下記のように表示されています。

//list[micchie_list1][Playgroundの初期表示]{
package main

import (
  "fmt"
)

func main() {
  fmt.Println("Hello, playground")
}
//}

ここで、@<code>{import}全体と、@<code>{main}の中に書いてある@<code>{fmt.Println("Hello, playground")}を消してしまいます。
スッキリしてしまいました。

//list[micchie_list2][main関数のみにする]{
package main

func main() {
}
//}

Women Who Go Tokyoでは、2年前に「じゃんけんゲーム」をみんなで作りました。
じゃんけんは、下記の理由により、ちょっとしたプログラミングの勉強にちょうど良いのです。

 * シンプルにロジックを考えられる。
 * テストを書きやすい。

これから、じゃんけんのロジックからテストまでを@<code>{Playground}で書いていきます。

==== 1. はじめに
まず、じゃんけんの手は下記の通りです。

 * グー
 * チョキ
 * パー

たとえば、

 * グーを@<code>{1}
 * チョキを@<code>{2}
 * パーを@<code>{3}

と数字で見立てると、下記のような計算式で勝ち負けを判別することができます。(`@<code>{%}は余りです)

//list[micchie_list3][じゃんけんのロジック]{
[結果] = ([自分] - [対戦相手] + 3) % 3
//}

この結果が、

 * @<code>{0}だったら引き分け
 * @<code>{1}だったら負け
 * @<code>{2}だったら勝ち

となります。
これを実際にGoで書いていこうと思います。

==== 2. 準備をする
じゃんけんの手や結果はわかりやすい名前をつけたいものです。
今回は特に、数字で計算をさせようとしているのでなおさらです。

よって下記のコードを@<code>{package main}の下に書きます。

//list[micchie_list4][じゃんけんの手と結果を定義する]{
type Hand int
type Result int

const (
  Rock Hand = iota + 1
  Scissors
  Paper
)

const (
  Invalid Result = iota - 1
  Even
  Lose
  Win
)
//}

goは他の言語にあるような列挙型を持っていないため、定数を使います。
最初にtypeで、手(Hand)と結果(Result)を定義し、定数で値を作ります。
ここで出てくる@<code>{iota}は、定数で利用される、型なしの連続する整数定数で、最初は@<code>{0}で初期化され、1つずつインクリメントされます。2行目移行の@<code>{iota}は省略が可能です。

==== 3. じゃんけんロジックを書く
mainの下にじゃんけんの処理を1つの関数として書きます。

2人で行うじゃんけんを想定しており、自分・対戦相手の手を引数とします。

 * 自分: @<code>{you}
 * 対戦相手: @<code>{challenger}

returnは、自分から見たじゃんけんの結果を返却します。

//list[micchie_list5][じゃんけんのロジック]{
func janken(you, challenger Hand) Result {
  r := (you - challenger + 3) % 3
  return Result(r)
}
//}

==== 4. main関数でじゃんけんを実行する
@<code>{you}と@<code>{challenger}にそれぞれ好きな手を入れてみてください。
例では、自分がグー、対戦相手がチョキです。

//list[micchie_list6][じゃんけんを実行する]{
func main() {
  you := Rock
  challenger := Scissors

  result := janken(you, challenger)
  fmt.Printf("you: %v, challenger: %v, Result: you %v...\n", you, challenger, result)
}
//}

`Runボタンを押下して実行してみると、下記のように表示されるはずです。

//list[micchie_list7][じゃんけんの結果]{
you: 1, challenger: 2, Result: you 2...
Program exited.
//}

これは、先程@<code>{const}で定義しているので、@<code>{you: Rock, challenger: Scissors, Result: you Win...}と同義です。
この演習では、そのまま数字で出力されてしまいますが、文字列に置き換えて表示させることも可能です。

@<code>{Playground}は、Shareボタンを押下することでソースコードのURLが発行でき、簡単に他の人に共有することができます。
この演習プログラムのURLは、@<href>{https://play.golang.org/p/zyXc7WsyQuC}です。

==== 5. テストを書く
@<code>{Playground}はテストを書くこともできます。
ポイントは2つです。

 * main関数がないこと。
 * @<code>{func Test[関数名](t *testing.T)`}を用意すること。

じゃんけんのテストを書いてみましょう。
Goのテストは構造体に予め期待結果の組み合わせを書いておき、ループで回しながらテストを行う手法(テーブルドリブンテスト)が推奨されています。
じゃんけんの全パターンを書くと、下記のようになります。

//list[micchie_list8][じゃんけんのテスト]{
func TestJanken(t *testing.T) {
  tests := []struct {
    user, computer Hand
    result         Result
  }{
    {Rock, Rock, Even},
    {Rock, Paper, Lose},
    {Rock, Scissors, Win},
    {Scissors, Rock, Lose},
    {Scissors, Paper, Win},
    {Scissors, Scissors, Even},
    {Paper, Rock, Win},
    {Paper, Paper, Even},
    {Paper, Scissors, Lose},
  }

  for _, test := range tests {
    result := Janken(test.user, test.computer)
    if result != test.result {
      t.Errorf("janken(%v, %v) = %v, want %v", test.user, test.computer, result, test.result)
    }
  }
}
//}

先ほどのプログラムの一番下にこの関数を追記し、@<code>{main}関数を削除すれば@<code>{Playground}でのテストの完成です。
Runボタンを押下して実行してみると、テストが実行され、下記のように表示されるはずです。

//list[micchie_list9][じゃんけんのテスト結果]{
=== RUN   TestJanken
--- PASS: TestJanken (0.00s)
PASS

Program exited.
//}

このテストプログラムのURLは、@<href>{https://play.golang.org/p/NvHvqUvb2xV}です。
さて、@<code>{Playground}を利用したGoの演習はここまでとなります。

== 3. わたしたちの目指す姿と今後の展望について
Women Who Go Tokyoの@mom0tomo@<fn>{mom0tomo_fn1}です。
普段は株式会社リブセンスのサーバサイドエンジニアとしてRuby on Railsを使って不動産サービスを開発、運用しています。

//footnote[mom0tomo_fn1][@<href>{https://twitter.com/mom0tomo}]

Women Who Go Tokyoは、Goに興味があり、学びたいと思っている女性が集まるコミュニティです。
本章ではWomen Who Go Tokyoの目指す姿と今後の展望についてお話しします。

=== なぜ「女性」コミュニティなのか？
技術の世界はまだまだ男性がマジョリティです。
特にまだ新しい言語であるGoでは、多くの人が使っている言語JSやPHP, Rubyなど)に比べ相対的に女性の人数が少ないです。

わたしは昨年たくさんのGoの勉強会やイベントに参加しましたが、その際、広い会場(50人〜100人)でたった一人の女性であることが珍しくありませんでした。それはわたしにとって悲しいことでした。

わたしはこのコミュニティを、女性やジェンダーマイノリティの方が、孤独を感じることなく安心感を得られる場所にしていきたいと思い、運営スタッフとして参画しています。

=== 目指す姿とこれからの活動について
わたしたちが目指すのは、技術を学ぶモチベーションがある全ての人に対し、ただ彼らが性別的にマイノリティであるというだけでひとりぼっちになるような状況を打ち壊すこと。

女性が技術コミュニティにおいてマイノリティであるのは、現在の社会情勢を見れば、あと十数年間は我慢しなければならない状況でしょう(大学の情報工学科の女性比率は何％でしょう？ちなみにわたしの卒業した大学では、2017年度入学者1,052名のうち女性は82名でわずか10%未満でした)。

わたしたちのコミュニティは、

 * 女性あるいはジェンダーマイノリティであり
 * Goに興味を持ち学ぼうとしている

 みなさんに向けてドアを開き、安心してプログラミングや創作活動ができる場所を提供することを目指します。
またそれを実現するために、2018年は以下の2つのアクションをとっていきます。

==== 1. 参加者が安心できる、クリーンであたたかいコミュニティ運営を続けること。
イベントでは女性やジェンダーマイノリティの方々に不快感を与える表現やシチュエーションをつくらないように努めます。
そしてSlackグループでも困ったことや相談ごとがあれば気軽にみんなで話し合える環境を整えたいと思っています。

また、先日GTUG Girlsのみなさまとの共催イベントで教えてもらった「なごみタイム」(お菓子をたべながらアイスブレイクする時間)は、参加者どうしのアイスブレイクにちょうどよかったので、Women Who Go Tokyoでも「Gopherカフェ」として取り入れたいと思っています。

==== 2. 参加者が教えてもらうだけではなく、参加者やスタッフ同士で教え合える機会をつくること。
これまでWomen Who Go Tokyoでは、Goを積極的に導入している企業のエンジニアの方々に講師になっていただき、講義形式で教えていただくというイベントを多数開催してきました。

これからも多様なレベルの参加者に合わせ、講義形式で教えていただくイベントは続けていきたいと考えています。
それに加えて今後は、参加者がプログラミングや創作活動を行いながら、互いに教え合うイベントも企画したいと考えています。

ハンズオン形式やものづくりイベントの際も、わたしたちスタッフがみんなでサポートしますので、初心者の方もどうぞ安心してご参加ください。
また、質問やわからないことがあればSlackでも気軽に質問し合っていますので、ぜひ一度参加してみてください。

=== 「女性限定」のコミュニティであるというイメージを払拭すること。
わたしたちはGoを学ぶモチベーションがあるすべての人に対し、オープンなコミュニティでありたいと思っています。
わたしたちが目指すのは、性別上マイノリティであるというだけで、イベントやコミュニティに参加する際に不安や落ち着かなさを感じるような状況をなくすことです。男性を排除することはわたしたちの目的ではありません。

ふだんのイベントの参加者については女性とジェンダーマイノリティに限定していますが、講師やチューター、運営のボランティアとして性別に関わらず多くの方々にご支援、ご賛同いただき活動してきました。
わたしたちは、わたしたちの考えに賛同していただけるみなさんとともにこれからも活動していきたいと強く願っています。

また先日、わたしたちはHumans Who Go Tokyoというもくもく会を開催しました。これはふだんのイベントとは異なり、性別の隔てなく全ての人にあてて公開したイベントです。
第一回ということで参加者はスタッフが中心でしたが、有志のGopherが集まってもくもくする楽しいイベントとなりました。
このようなイベントも、形式を模索しながら今後も続けていくつもりです。

=== 私たちの理念に賛同してくださるみなさまへ
Women Who Go Tokyoは、尊敬すべきエンジニアの方々のサポート、そして活動にご賛同いただいた企業のみなさまからの会場提供など多くの方々からご協力いただき、活動を続けてきました。
これまでご支援いただいたみなさまに改めて感謝します。そして、これからもよろしくお願いいたします。

== 4. さいごに
Women Who Go Tokyoは、もっと多くの方々と一緒にGoを学んでいきたいと考えています。Goをさわってみたい方ならどなたでも大歓迎です！
Macだけではなく、Windows、Ubuntu環境も用意して、環境構築で躓いたときにはいつでもサポートできるようにしています。
ぜひ遊びに来てください。わたしたちはGopher仲間を待っています。
そして、一緒に活動を盛り上げてくださる方を募集しています。少しでもご興味がある方は、ぜひ@wwg_tokyo@<fn>{wwg_tokyo_fn1}のTwitterアカウントまでご連絡ください。
