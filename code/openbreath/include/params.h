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
#define OB_PRINT_WELCOME
#define OB_HOOK_CHAR 's'

//  Esc
#define OB_ESC_PIN D4

//  Serial
//#define OB_WAIT_FOR_SERIAL
#define OB_TERMINAL_BAUD_RATE 115200
#define OB_TERMINAL_SERIAL Serial
#define OB_SERIAL_WAIT_TIME 5000

// Breathing
#define OB_DEFAULT_PATTERN Normal1