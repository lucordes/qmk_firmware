/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0
#define PRODUCT_ID      0
#define DEVICE_VER      0
#define MANUFACTURER    LucaCordes
#define PRODUCT         Transsplit
#define DESCRIPTION     transparent split keyboard

/* key matrix size */
// Rows are doubled-up
#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROWS 8
#define MATRIX_COLS 6
#define MATRIX_ROW_PINS { B2, B3, B1, F7 }
#define MATRIX_COL_PINS { B5, B4, E6, D7, C6, D4 }

#define RGB_DI_PIN B2
#define RGBLED_NUM 12    // Number of LEDs (each hand)
#define RGBLED_SPLIT { 6, 6 }
#define RGBLIGHT_ANIMATIONS

/* Split Defines */
#define SPLIT_HAND_PIN B6
#define SOFT_SERIAL_PIN D3

#define USE_SERIAL

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5
