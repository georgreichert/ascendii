#ifndef ASCENDII_H
#define ASCENDII_H

#if     _WIN32_WINNT < 0x0500
#undef  _WIN32_WINNT
#define _WIN32_WINNT   0x0500
#endif
#include <windows.h>
#include <string>
#include <winuser.h>
#include <chrono>
#include <stdlib.h>

#define KEY_UP    720
#define KEY_LEFT  750
#define KEY_RIGHT 770
#define KEY_DOWN  800
#define KEY_ESC   270
#define KEY_ENTER 130
#define KEY_SPACE 320

#define COLOR_YELLOW    14
#define COLOR_RED       12
#define COLOR_CYAN      11
#define COLOR_WHITE     15
#define COLOR_GREEN     10
#define COLOR_BLUE      9
#define COLOR_PINK      13
#define BG_COLOR_GREEN  160
#define BG_COLOR_RED    192
#define BG_COLOR_YELLOW 224

#include "headers/debuglog.h"
#include "headers/ascendiitime.h"
#include "headers/screen.h"
#include "headers/sprite.h"
#include "headers/animation.h"
#include "headers/moveanimation.h"
#include "headers/gamestate.h"
#include "headers/menuelement.h"
#include "headers/substate.h"

#endif // ASCENDII_H
