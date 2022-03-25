#include "louckousse.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_GG:  // One key copy/paste
            if (record->event.pressed) {
                SEND_STRING("\nGG\n");
            } else {
                tap_code16(KC_F10);
                tap_code16(KC_W);
            }
            break;
        case KC_GL:
            if (record->event.pressed) {
                SEND_STRING("\ngl hf\n");
            }
            break;
        case DSK_PRV:
            if (record->event.pressed) {
                if (user_config.osIsLinux) {
                    tap_code16(C(A(KC_LEFT)));
                } else {
                    tap_code16(C(G(KC_LEFT)));
                }
            }
            break;
        case DSK_NXT:
            if (record->event.pressed) {
                if (user_config.osIsLinux) {
                    tap_code16(C(A(KC_RIGHT)));
                } else {
                    tap_code16(C(G(KC_RIGHT)));
                }
            }
            break;
        case PRINT:
            if (record->event.pressed) {
                if (user_config.osIsLinux) {
                    tap_code16(C(S(KC_PSCR)));
                } else {
                    tap_code16(S(G(KC_S)));
                }
            }
            break;
        case LOCK:
            if (record->event.pressed) {
                if (user_config.osIsLinux) {
                    tap_code16(LCA(KC_L));
                } else {
                    tap_code16(G(KC_L));
                }
            }
            break;
        case KC_OS:
            if(record->event.pressed) {
                user_config.osIsLinux = !user_config.osIsLinux;
            }
            #ifdef PKRGB
            if (user_config.osIsLinux) {
                rgblight_sethsv(225, 215, 100);
            } else {
                rgblight_sethsv(169, 215, 100);
            }
            #endif
            break;
        case M_SFT2:
            if (record->event.pressed) {
                tap_code16(S(KC_BTN3));
            }
            break;
    }
    return true;
}

enum combos {
  JM_QUOT,
  BG_GRV,
  GV_CIRC,
  JL_MINS
};

const uint16_t PROGMEM jm_combo[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM bg_combo[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM gv_combo[] = {KC_G, KC_V, COMBO_END};
const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [JM_QUOT] = COMBO(jm_combo, KC_SCLN),
  [BG_GRV] = COMBO(bg_combo, KC_SLASH),
  [GV_CIRC] = COMBO(gv_combo, KC_CIRC),
  [JL_MINS] = COMBO(jl_combo, KC_TAB)
};

#ifdef PKRGB
#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM NAVMT_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {18, 3, HSV_RED}
);
const rgblight_segment_t PROGMEM FUNMT_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {18, 3, HSV_CYAN}
);
const rgblight_segment_t PROGMEM NUMMT_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {18, 3, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM SYMMT_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {18, 3, HSV_GREEN}
);
const rgblight_segment_t PROGMEM MSE_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {18, 3, HSV_PINK}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    NAVMT_layer,
    FUNMT_layer,
    NUMMT_layer,
    SYMMT_layer,
    MSE_layer
);
#endif
#endif

void keyboard_post_init_user(void) {
    user_config.osIsLinux = true;
    #ifdef PKRGB
    #ifdef RGBLIGHT_LAYERS
    rgblight_layers = my_rgb_layers;
    #endif
    #endif
    #ifdef TRACKBALL_MATRIX_ROW
    trackball_sethsv(235, 200, 100);
    #endif
}

#ifdef PKRGB
#ifdef RGBLIGHT_LAYERS
// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(0, led_state.caps_lock);
//     return true;
// }

// layer_state_t default_layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(1, layer_state_cmp(state, _DVORAK));
//     return state;
// }

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, NAVMT));
    rgblight_set_layer_state(1, layer_state_cmp(state, FUNMT));
    rgblight_set_layer_state(2, layer_state_cmp(state, NUMMT));
    rgblight_set_layer_state(3, layer_state_cmp(state, SYMMT));
    rgblight_set_layer_state(4, layer_state_cmp(state, MSE));
    return state;
}
#endif
#endif

#ifdef TRACKBALL_MATRIX_COL
void process_trackball_user(trackball_record_t *record) {
    if (record->type & TB_MOVED) {
        report_mouse_t currentReport = pointing_device_get_report();
        currentReport.h += record->x;
        currentReport.v -= record->y;
        pointing_device_set_report(currentReport);
        record->type &= ~TB_MOVED;
    }
}
#endif
