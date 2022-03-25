#pragma once
#include QMK_KEYBOARD_H

#include <stdio.h>
#include "wrappers.h"
#include "pointing_device.h"

/* Define layer names */
enum userspace_layers {
    CMT = 0,
    CMK,
    NAVMT,
    FUNMT,
    NUMMT,
    SYMMT,
    MSE
};

typedef union {
    struct {
        bool osIsLinux;
    };
} user_config_t;

user_config_t user_config;

enum custom_keycodes {
    KC_GG = SAFE_RANGE,
    KC_GL,
    DSK_NXT,
    DSK_PRV,
    PRINT,
    LOCK,
    KC_OS,
    M_SFT2
};

#define KC_EUR ALGR(KC_5)
#define ST_ENT SFT_T(KC_ENT)

#define RSE_DEL LT(NAVMT, KC_DEL)
#define LWR_BSP LT(SYMMT, KC_BSPC)

#define B_PREV A(KC_LEFT)
#define B_NEXT A(KC_RIGHT)


// mod tap
#define CTRL_MN CTL_T(KC_MINS)
#define ALT_BO ALT_T(KC_LBRC)
#define ALT_BE ALT_T(KC_RBRC)

// layer change
#define ST_SPC SFT_T(KC_SPC)
#define GO_SC2 DF(SC2_B)
#define GO_GAME DF(GAME_B)
#define GO_BASE DF(CMT)
#define GO_CMK DF(CMK)

// Homerow mod specific keycodes
#define NAV_DEL LT(NAVMT, KC_DEL)
#define FUN_ENT LT(FUNMT, KC_ENT)
#define NUM_SPC LT(NUMMT, KC_SPC)
#define SYM_BSP LT(SYMMT, KC_BSPC)
#define MSE_ESC LT(MSE, KC_ESC)
#define MK_A LGUI_T(KC_A)
#define MK_R LALT_T(KC_R)
#define MK_S LCTL_T(KC_S)
#define MK_T LSFT_T(KC_T)
#define MK_N RSFT_T(KC_N)
#define MK_E RCTL_T(KC_E)
#define MK_I LALT_T(KC_I)
#define MK_O RGUI_T(KC_O)
#define MK_X ALGR_T(KC_X)
#define MK_DOT ALGR_T(KC_DOT)

// wrapper for using what's in wrappers.h
#define LAYOUT_kyria_pretty_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_bastyl_pretty_wrapper(...) LAYOUT_5x6(__VA_ARGS__)
#define LAYOUT_crbn_pretty_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_lily58_pretty_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_tbk_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

bool process_record_user(uint16_t keycode, keyrecord_t *record);
