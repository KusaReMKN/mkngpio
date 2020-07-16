### 説明

**`mkngpio`** は Raspberry Pi の GPIO を C から利用しやすくするためのライブラリである。
このライブラリは `mkngpio.h` と `mkngpio.c` からなる。
このライブラリは C++ からの利用も想定されている。
このライブラリでは、内部処理に `open`(2) などを利用する代わりに `fopen`(3) などを利用しているため、***処理の反映に時間がかかる恐れがある***ことに留意されたい。

#### 関数の戻り値

mkngpio のすべての関数は以下のいずれかの値を返す:

戻り値|ステータス
---|---
1|成功; 値は `1` (`ReadGPIO`)
0|成功; 値は `0` (`ReadGPIO`)
-1|ポート番号が異常
-2|`.../gpio/export`, `.../gpio/unexport` を開けなかった
-3|入出力方向が異常
-4|`.../gpio/.../direction` を開けなかった
-5|`.../gpio/.../value` を開けなかった


#### 定義済みの値

```c
enum { IN = 0, OUT = 1 };
```

関数 `SetGPIODirection` で入出力方向を指定するときに利用する値である。

#### GPIO の利用開始

```c
int ExportGPIO(
    int nPortNum    // ポート番号 [0, 27]
);
```

ポートの利用開始をシステムに通知する。

#### GPIO の利用終了

```c
int UnexportGPIO(
    int nPortNum    // ポート番号 [0, 27]
);
```

ポートの利用終了をシステムに通知する。

#### GPIO の入出力方向

```c
int SetGPIODirection(
    int nPortNum,   // ポート番号 [0, 27]
    int nInOut      // 入力: IN(=0), 出力: OUT(=1)
);
```

ポートの入出力方向を指定する。
方向指定には `IN` や `OUT` の定義済みの値を利用できる。

#### GPIO への出力

```c
int WriteGPIO(
    int nPortNum,   // ポート番号 [0, 27]
    int nValue      // 値: 0, !0
);
```

ポートの出力値を指定する。
出力値は `0` か `!0` かで判断される。

#### GPIO からの入力

```c
int WriteGPIO(
    int nPortNum,   // ポート番号 [0, 27]
);
```

ポートの入力値を取得する。
値は `0` か `1` で得られる。
