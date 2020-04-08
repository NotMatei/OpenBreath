#pragma once

#include "Arduino.h"

//Version info
#define OB_MAJOR_VER 0
#define OB_MINOR_VER 1
#define OB_DECORATOR ""

//Build date info
#define OB_BUILD_DATE "8/4/2020"

//Settings
//  Misc
#define OB_WAIT_FOR_SERIAL
#define OB_PRINT_WELCOME

//  Esc
#define OB_ESC_PIN 9

//  Serial
#define OB_TERMINAL_BAUD_RATE 115200
#define OB_TERMINAL_SERIAL Serial