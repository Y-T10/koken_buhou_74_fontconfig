# サンプルコード
工学研究部部報74号に掲載された「フォントよ、君はどこにいる」のサンプルコードリポジトリです．
記事に関するプログラムも置いています．

## お詫び
著者の勘違いで11/12に電子と冊子が頒布されるとは考えていませんでした．
11/14の深夜0時までに投稿します．よろしくおねがいします．

## プログラムの説明
各プログラムは同名のディレクトリに収納されており、その一覧は以下のとおりです．

| プログラム名 | 説明 |
| :-------------- | ---- |
| `find-font`  | 記事に掲載されているコードのプログラム． |
| `find-font_error`  | エラー処理を追加した`find-font`． |
| `find-font_list`  | 関数`FcFontList`を用いてフォントを探すプログラム． |

これらのプログラムは生成されると`bin`ディレクトリに格納されます．

## プログラムの実行方法
```bash
$ cd path/to/bin
$ ./find-font* "font name"
```

## ライセンス
### fontconfig
fontconfig/COPYING
Copyright © 2000,2001,2002,2003,2004,2006,2007 Keith Packard
Copyright © 2005 Patrick Lam
Copyright © 2007 Dwayne Bailey and Translate.org.za
Copyright © 2009 Roozbeh Pournader
Copyright © 2008,2009,2010,2011,2012,2013,2014,2015,2016,2017,2018,2019,2020 Red Hat, Inc.
Copyright © 2008 Danilo Šegan
Copyright © 2012 Google, Inc.


Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation, and that the name of the author(s) not be used in
advertising or publicity pertaining to distribution of the software without
specific, written prior permission.  The authors make no
representations about the suitability of this software for any purpose.  It
is provided "as is" without express or implied warranty.

THE AUTHOR(S) DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY SPECIAL, INDIRECT OR
CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
PERFORMANCE OF THIS SOFTWARE.
