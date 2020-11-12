/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#define VENDOR_ID       0
#define PRODUCT_ID      0
#define DEVICE_VER 0
#define MANUFACTURER LucaCordes
#define PRODUCT SelfmadeOrtho
#pragma once

#include "config_common.h"

#define DIODE_DIRECTION COL2ROW
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define MATRIX_ROWS 4
#define MATRIX_COLS 12
///*
//clrearcase
#define MATRIX_COL_PINS { C6,E6,B4,B5,D3,B2,B3,B1,F7,F6,F5,F4 }
#define MATRIX_ROW_PINS { D7,D1,D2,D0}

#define B6_AUDIO

#ifdef AUDIO_ENABLE
  #define STARTUP_SONG SONG(STARTUP_SOUND)
#endif
//*/

/*
#define MATRIX_COL_PINS { D7,E6,D1,D4,D3,B2,B3,B1,F7,F6,B4,B5 }
#define MATRIX_ROW_PINS { F4,F5 ,D2,D0}
#define UNUSED_PINS
*/
#define UNICODE_SELECTED_MODES UC_LNX
//#define UNICODE_SONG_LNX  UNICODE_LINUX
#define PERMISSIVE_HOLD



