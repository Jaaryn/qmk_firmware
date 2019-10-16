#include QMK_KEYBOARD_H

#include "sten.h"
#include "config.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_butter(
  	STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
   	STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR
  )
};

uint32_t processQwerty(bool lookup) {
		P( LSU | RD, 		          SEND(KC_BSPC));
    P( LSD | RZ,   			 	    SEND(KC_SPC));

    P( LSU | LFT,             SEND(KC_ESC));
		P( LSD | LK,					    SEND(KC_LSFT));
		P( RZ  | RS,					    SEND(KC_RSFT));
    P( RP  | RL,    			    SEND(KC_LGUI));
    P( RT  | RD,    			    SEND(KC_LCTL));
    P( RL  | RT,    			    SEND(KC_LALT));
		P( LSU | LSD | LFT | LK,	SEND(KC_LCTL));
		P( RS  | RT  | RD  | RZ,	SEND(KC_ENT));

    P( FUNCT | RF,         SEND(KC_F1));
    P( FUNCT | RP,         SEND(KC_F2));
    P( FUNCT | RL,         SEND(KC_F3));
    P( FUNCT | RT,         SEND(KC_F4));
    P( FUNCT | RF | RR,    SEND(KC_F5));
    P( FUNCT | RP | RB,    SEND(KC_F6));
    P( FUNCT | RL | RG,    SEND(KC_F7));
    P( FUNCT | RT | RS,    SEND(KC_F8));
    P( FUNCT | RR,         SEND(KC_F9));
    P( FUNCT | RB,         SEND(KC_F10));
    P( FUNCT | RG,         SEND(KC_F11));
    P( FUNCT | RS,         SEND(KC_F12));

    P( MOVE | RF,     SEND(KC_LEFT));
    P( MOVE | RP,     SEND(KC_DOWN));
    P( MOVE | RL,     SEND(KC_UP));
    P( MOVE | RT,     SEND(KC_RIGHT));
    P( MOVE | ST1,    SEND(KC_PGUP));
    P( MOVE | ST2,    SEND(KC_PGDN));

    P( NUMB | LSU,    SEND(KC_1));
    P( NUMB | LFT,    SEND(KC_2));
    P( NUMB | LP,     SEND(KC_3));
    P( NUMB | LH,     SEND(KC_4));
    P( NUMB | ST1,    SEND(KC_5));
    P( NUMB | RF,     SEND(KC_6));
    P( NUMB | RP,     SEND(KC_7));
    P( NUMB | RL,     SEND(KC_8));
    P( NUMB | RT,     SEND(KC_9));
    P( NUMB | RD,     SEND(KC_0));

    P( NUMA | LSU,    SEND(KC_1));
    P( NUMA | LFT,    SEND(KC_2));
    P( NUMA | LP,     SEND(KC_3));
    P( NUMA | LH,     SEND(KC_4));
    P( NUMA | ST1,    SEND(KC_5));
    P( NUMA | RF,     SEND(KC_6));
    P( NUMA | RP,     SEND(KC_7));
    P( NUMA | RL,     SEND(KC_8));
    P( NUMA | RT,     SEND(KC_9));
    P( NUMA | RD,     SEND(KC_0));

    P( SYMB | LP | LW,      SEND(KC_LSFT); SEND(KC_9));       // (
    P( SYMB | LH | LR,      SEND(KC_LSFT); SEND(KC_0));       // )
    P( SYMB | ST1 | ST2,    SEND(KC_GRV));                    // `
    P( SYMB | RR  | RF,    	SEND(KC_LSFT); SEND(KC_3));       // #
    P( SYMB | LFT | LK,     SEND(KC_LSFT); SEND(KC_4));       // $
    P( SYMB | LSU,          SEND(KC_LSFT); SEND(KC_1));       // !
    P( SYMB | LSD,          SEND(KC_LSFT); SEND(KC_5));       // %
    P( SYMB | LFT,          SEND(KC_LSFT); SEND(KC_2));       // @
    P( SYMB | LK,           SEND(KC_LSFT); SEND(KC_6));       // ^
    P( SYMB | LP,           SEND(KC_LSFT); SEND(KC_LBRC));    // {
    P( SYMB | LW,           SEND(KC_LBRC));
    P( SYMB | LH,           SEND(KC_LSFT); SEND(KC_RBRC));    // }
    P( SYMB | LR,           SEND(KC_RBRC));
    P( SYMB | ST1,          SEND(KC_LSFT); SEND(KC_BSLS));    // |
    P( SYMB | ST2,          SEND(KC_LSFT); SEND(KC_GRV));     // ~
    P( SYMB | RP | RB,      SEND(KC_QUOT));
    P( SYMB | RP | RG,      SEND(KC_LSFT); SEND(KC_QUOT));    // "
    P( SYMB | RF,           SEND(KC_KP_PLUS));
    P( SYMB | RR,           SEND(KC_LSFT); SEND(KC_7));       // &
    P( SYMB | RP,           SEND(KC_MINS));
    P( SYMB | RB,           SEND(KC_EQL));
    P( SYMB | RL,           SEND(KC_SLSH));
    P( SYMB | RG,           SEND(KC_COMM));
    P( SYMB | RT,           SEND(KC_PAST));
    P( SYMB | RS,           SEND(KC_DOT));

    P( LSU | LSD,    SEND(KC_A));
    P( LFT | LK,     SEND(KC_O));
    P( LP  | LW,     SEND(KC_E));
    P( LH  | LR,     SEND(KC_U));
    P( ST1 | ST2,    SEND(KC_I));
    P( RF  | RR,     SEND(KC_D));
    P( RP  | RB,     SEND(KC_H));    
    P( RG  | RL,     SEND(KC_T));
    P( RT  | RS,     SEND(KC_N));
    P( RD  | RZ,     SEND(KC_S));
    P( LSU,          SEND(KC_SLSH));
    P( LSD,          SEND(KC_SCLN));
    P( LFT,          SEND(KC_COMM));
    P( LK,           SEND(KC_Q));
    P( LP,           SEND(KC_DOT));
    P( LW,           SEND(KC_J));
    P( LH,           SEND(KC_P));
    P( LR,           SEND(KC_K));
    P( ST1,          SEND(KC_Y));
    P( ST2,          SEND(KC_X));
    P( RF,           SEND(KC_F));
    P( RR,           SEND(KC_B));
    P( RP,           SEND(KC_G));
    P( RB,           SEND(KC_M));
    P( RL,           SEND(KC_C));
    P( RG,           SEND(KC_W));
    P( RT,           SEND(KC_R));
    P( RS,           SEND(KC_V));
    P( RD,           SEND(KC_L));
    P( RZ,           SEND(KC_Z));

    return 0;
}

size_t keymapsCount  = sizeof(keymaps)/sizeof(keymaps[0]);
