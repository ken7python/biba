# Danmaku++

## 概要
C++とRaylibを使った弾幕シューティングゲームです。  
敵キャラクターが弾を発射し、プレイヤーは被弾を避けてスコアを競います。

## ディレクトリ構成

```
.
├── danmaku.cpp         # メインゲームロジック
├── background.png      # 背景画像
├── BGM.mp3             # ゲームBGM
├── gameover.mp3        # ゲームオーバー時の効果音
├── README.md           # このファイル
```

## 必要環境

- C++ コンパイラ（例: c++,g++）
- Raylib ライブラリ
- 音声・画像ファイル（同梱）

## ビルド方法(MacOS)

ターミナルで以下のコマンドを実行してください。

```
c++ -std=c++11 danmaku.cpp libraylib.a -framework Cocoa -framework IOKit
```

## 実行方法(MacOS)

```
./a.out
```

## 操作方法

- スペースキー：ゲーム開始／リトライ
- 矢印キー：自機の移動

## その他
その他、プログミングクラブで使用したC/C++の練習コードも公開しています。

## 音楽素材
BGM：魔王魂（https://maou.audio/ ）

効果音：効果音ラボ（https://soundeffect-lab.info/ ）

※いずれも各サイトの利用規約に従って使用しています。
## ライセンス

このプロジェクトはMITライセンスです。