/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"

/* Notes:
 * - standard layer 0 press activations.
 * - Leaving _______ in spots where we're going to do something else.
 * - Single KC_NO is in a location that isn't mapped to a key -- can leave that one alone.
 */
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(    
    KC_TAB,  KC_Q,       KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,      KC_U,       KC_I,    KC_O,       KC_P,     KC_MINS, KC_EQL,
    _______, KC_A,       KC_S,   _______,  KC_F,    KC_G,    KC_H,      KC_J,       KC_K,    KC_L,       KC_SCLN, KC_ENT,    
    // _______, KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,    KC_N,      KC_M,       KC_COMM, KC_DOT,     KC_SLASH,  _______,
    KC_LSHIFT, KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,    KC_N,      KC_M,       KC_COMM, KC_DOT,     KC_SLASH,  KC_RSHIFT,
    // _______, KC_LALT,  KC_LGUI,  KC_NO,    _______,        KC_SPC,   KC_RGUI, _______,      KC_RGUI, _______ )};
     _______, KC_LALT,  KC_LGUI,  KC_NO,    KC_BSPC,        KC_SPC,   KC_RGUI, _______,      KC_RGUI, _______ )};

 
void setupKeymap() {

    uint32_t layer0Tap[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,  _______,
    KC_ESC,  _______,  _______,  KC_D,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,
    // KC_LPRN,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  KC_RPRN,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,
    KC_GRV, _______, _______, KC_NO, _______,  _______, _______, _______,      _______, KC_QUOT);

    uint32_t layer0Hold[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,  _______,
    KC_LCTRL,  _______,  _______,  LAYER_2,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,
    // KC_LSHIFT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  KC_RSHIFT,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,
    LAYER_1, _______, _______, KC_NO, _______,  _______, _______, _______,      _______, LAYER_1);

    /* Layer 1: Numbers, a few other things, activated by SUPER keys in bottom left/right */
    uint32_t layer1Press[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
    KC_GRV,  KC_1,      KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,    KC_0,     KC_LBRC,   KC_RBRC,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  KC_QUOT,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, KC_BSLS,  _______,
    _______, _______, _______, KC_NO, _______,  _______, _______, _______,      _______, _______ );

    /* Layer 2 Press: Arrows and Audio */
    uint32_t layer2Press[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT, _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,
    _______, _______, _______, KC_NO, _______,  _______,        KC_MUTE,  KC_VOLDOWN,  KC_VOLUP, KC_MEDIA_PLAY_PAUSE);

    /* Layer 2 Hold: Enable Layer 3 on hold of 'F' */
    uint32_t layer2Hold[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,  _______,
    _______,  _______,  _______,  _______,  LAYER_3,  _______,  _______,  _______,  _______, _______, _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,
    _______, _______, _______, KC_NO, _______,  _______, _______, _______,      _______, _______ );

    /* Layer 3 Press: HOME/PGUP/PGDN/END */
    uint32_t layer3Press[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP, KC_END, _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,
    _______, _______, _______, KC_NO, _______,  _______, _______, _______,      _______, _______ );

    /* Layer 4 Press: Numpad (currently unused) */
    uint32_t layer4Press[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_KP_7,  KC_KP_8, KC_KP_9, _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_KP_4,  KC_KP_5, KC_KP_6, _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_KP_1,  KC_KP_2, KC_KP_3, _______,  _______,
    _______, _______, _______, KC_NO, _______,  _______,   KC_KP_0,     _______,  _______, _______ );

    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L0, Method::MT_TAP,  layer0Tap[row][col]);
            matrix[row][col].addActivation(_L0, Method::MT_HOLD, layer0Hold[row][col]);
            matrix[row][col].addActivation(_L1, Method::PRESS,   layer1Press[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS,   layer2Press[row][col]);
            matrix[row][col].addActivation(_L2, Method::MT_HOLD, layer2Hold[row][col]);
            matrix[row][col].addActivation(_L3, Method::PRESS,   layer3Press[row][col]);
            matrix[row][col].addActivation(_L4, Method::PRESS,   layer4Press[row][col]);
        }
    }

}

/* THIS IS WHAT I'M REPRODUCING FROM QMK, MORE OR LESS */

#if 0
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    KC_TAB,           KC_Q,     KC_W,     KC_E,               KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_MINS, KC_EQL,
    LCTL_T(KC_ESC),   KC_A,     KC_S,     LT(_FN_2,KC_D),     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_ENT,
    KC_LSPO,          KC_Z,     KC_X,     KC_C,               KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC,
    LT(_FN1,KC_GRV),         KC_LALT,  KC_LGUI,  KC_NO,    KC_BSPC,   KC_SPC,   KC_RGUI,  TG(_FN_4),  KC_RGUI, LT(_FN1, KC_QUOT)  
  ),
  
  [_FN1] = LAYOUT(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_LBRC,  KC_RBRC,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_QUOT,  
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_BSLS,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),
  
  [_FN_2] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,
    _______,  _______,  _______,  _______,  MO(_FN_3),  _______,  KC_LEFT,  KC_DOWN,    KC_UP, KC_RIGHT,  _______, _______, 
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  KC__MUTE,  KC__VOLDOWN,  KC__VOLUP,  KC_MPLY
  ),
  [_FN_3] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,   KC_END,  _______, _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),
  [_FN_4] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_KP_7,  KC_KP_8,  KC_KP_9,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_KP_4,  KC_KP_5,   KC_KP_6,  _______, _______,  
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_KP_1,  KC_KP_2,  KC_KP_3,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  KC_KP_0,  _______,  _______,  _______
  ) 
};
#endif
