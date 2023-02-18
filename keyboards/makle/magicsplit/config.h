// Copyright 2022 Kleemann (@Kleemann)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 10

#define SPLIT_USB_DETECT
#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2, NO_PIN, NO_PIN, NO_PIN }
#define MATRIX_ROW_PINS_RIGHT { B0, F6, F7, B1, B3 }
#define MATRIX_COL_PINS_RIGHT { F1, C7, D5, B7, B5, B4, E6, D7, C6, D4 }
#define ENCODERS_PAD_A_RIGHT { F5 }
#define ENCODERS_PAD_B_RIGHT { F4 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D0