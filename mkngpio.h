#pragma once
#ifndef __MKN_GPIO_H__
#define __MKN_GPIO_H__

#include <stdio.h>

#ifdef __cplusplus
extren "C"
{
#endif

  enum
  {
    IN = 0,
    OUT = 1,
  };

  // GPIO を利用開始する
  int ExportGPIO(int);

  // GPIO を利用終了する
  int UnexportGPIO(int);

  // GPIO の入出力を設定する
  int SetGPIODirection(int, int);

  // GPIO に書き込む
  int WriteGPIO(int, int);

  // GPIO を読み込む
  int ReadGPIO(int);

#ifdef __cplusplus
}
#endif

#endif
