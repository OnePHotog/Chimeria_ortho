// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "chimera_ortho.h"
#include "action_layer.h"
//#include "eeconfig.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define KC_QWERTY 0
#define KC_CAPP 1    /*DVORAK*/
#define KC_NAV 2     /*MISC*/
#define KC_NUMPAD 3  /*LOWER*/
#define KC_SYMBOLS 4 /*UPPER*/


enum chimera_ortho_layers
{
	KC_QWERTY,
	KC_CAPP,
	KC_NAV,
	KC_NUMPAD,
	KC_SYMBOLS,
	_MACROS
};

// #define KC_NMPD TG(_NUMPAD)
// #define KC_SYMB TG(_SYMBOLS)
// #define KC_SPFN LT(_NAV,KC_EQL)
#define KC_SCTL MT(MOD_LCTL, KC_LBRC)
#define KC_SCTR MT(MOD_LCTL, KC_RBRC)
#define KC_SPLT MT(MOD_LALT, KC_MINS)
#define KC_SPRT MT(MOD_LALT, KC_1)
//#define KC_GBRC MT(MOD_RGUI, KC_8)
//#define KC_GQOT MT(MOD_LGUI, KC_QUOT)
#define KC_MESC LT(_MACROS, KC_ESC)
#define KC_INCL M(0)
#define KC_PULL M(1)
#define KC_PUSH M(2)
#define KC_SCAP M(3)
#define KC_SCOF M(4)
#define KC_CAD LALT(LCTL(KC_DEL))
#define KC_CLOS LALT(KC_F4)
#define KC_RESET RESET
#define KC_WIN1 LGUI(KC_1)
#define KC_WIN2 LGUI(KC_2)
#define KC_WIN3 LGUI(KC_3)
#define KC_WIN4 LGUI(KC_4)
#define KC_WIN5 LGUI(KC_5)
#define KC_CLFT LCTL(KC_LEFT)
#define KC_SLFT S(KC_LEFT)
#define KC_SRHT S(KC_RGHT)
#define KC_CRHT LCTL(KC_RGHT)
#define LONGPRESS_DELAY 150
//#define LAYER_TOGGLE_DELAY 300

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_ KC_TRNS 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [KC_QWERTY] = KEYMAP(  
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
     MESC, Q  , W  , E  , R  , T  ,LGUI,      QWERTY, Y, U  , I,    O,   P,    DEL,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
     TAB , A  , S  , D  , F  , G  ,LALT,      CAPP,   H, J  , K,    L,   SCLN, QUOT,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,LCTL,      NAV,    N, M  , COMM, DOT, SLSH, ENT,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                       NUMPAD,BSPC,                 SPC, SYMBOLS
  // \------------------+----+----+---/       \---+----+----+-------------------/
  ),

  //dvorak
  [KC_CAPP] = KEYMAP(  
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
     MESC,QUOT,COMM, DOT, P  , Y  ,LGUI,      QWERTY, F  , G  , C  , R  , L , DEL,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
     TAB , A  , O  , E  , U  , I  ,LALT,      CAPP,   D  , H  , T  , N  , S ,SLSH,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
     LSFT,SCLN, Q  , J  , K  , X  ,LCTL,      NAV,    B  , M  , W  , V  , Z , ENT,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                       NUMPAD,BSPC,                  SPC , SYMBOLS   
  // \------------------+----+----+---/       \---+----+----+-------------------/
  ),

  //MISC
  [KC_NAV] = KEYMAP(  
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
     MESC,    ,    ,    ,    ,    ,LGUI,      QWERTY, LPRN, 7  , 8  , 9  , NO ,BSPC,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
     TAB ,    ,    ,    ,    ,    ,LALT,      CAPP,   RPRN, 4  , 5  , 6  ,PPLS,PMNS,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
     LSFT,    ,    ,    ,    ,    ,LCTL,      NAV,    0 ,   1  , 2  , 3  ,PAST,PSLS,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                       NUMPAD,BSPC,                 SPC, SYMBOLS   
  // \------------------+----+----+---/       \---+----+----+-------------------/
  ),

  //LOWER
  [KC_NUMPAD] = KEYMAP(  
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC, APP,          ,CIRC,AMPR,ASTR,LPRN,RPRN,BSLS,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
     CAPS, 1  , 2  , 3  , 4  , 5  ,PGUP,          , 6  , 7  , 8  , 9  , 0  ,HOME,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         ,MINS,PEQL,LBRC,RBRC,BSLS,PGDN,          , NO ,LEFT,DOWN, UP ,RGHT, END,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                             ,    ,                     ,    
  // \------------------+----+----+---/       \---+----+----+-------------------/
  ),
  
  //UPPER
  [KC_SYMBOLS] = KEYMAP(  
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
     PWR ,WIN1,WIN2,WIN3,WIN4,WIN5, APP,          ,VOLU, NO ,MNXT,MSTP, NO ,CLOS,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         , F1 , F2 , F3 , F4 , F5 , F6 ,          ,MUTE,CLFT,SLFT,SRHT,CRHT, NO ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         , F7 , F8 , F9 ,F10 ,F11 , F12,          ,VOLD, NO , NO , NO , NO , NO ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                             ,    ,                    ,
  // \------------------+----+----+---/       \---+----+----+-------------------/
  ),

  


  [_MACROS] = KEYMAP(  
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,    ,          ,    ,    ,    ,    ,    ,RESET,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
         ,    ,    ,CAD ,    ,    ,    ,          ,    ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
     SCAP,    ,    ,    ,    ,    ,    ,          ,    ,    ,PULL,PUSH,    ,SCAP,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
                             ,    ,                    ,    
  // \------------------+----+----+---/       \---+----+----+-------------------/
  )

};


const uint16_t PROGMEM fn_actions[] = {

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case KC_QWERTY:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<KC_QWERTY);
          }
          return false;
          break;
        case KC_CAPP:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<KC_CAPP);
          }
          return false;
          break;
        case KC_NAV:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<KC_NAV);
          }
          return false;
          break;
        case KC_NUMPAD:
          if (record->event.pressed) {
            layer_on(KC_NUMPAD);
          } else {
            layer_off(KC_NUMPAD);
          }
          return false;
          break;
        case KC_SYMBOLS:
          if (record->event.pressed) {
            layer_on(KC_SYMBOLS);
          } else {
            layer_off(KC_SYMBOLS);
          }
          return false;
          break;
      }
    return true;
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    /* include some kind of library or header */
    case 0:
      if (record->event.pressed) {
        SEND_STRING("#include <>");
        return MACRO( T(LEFT), END);
      }
      break;
    case 1:
      if (record->event.pressed) {
        SEND_STRING("git pull");
        return MACRO( T(ENT), END );
      }
      break;
    case 2:
      if (record->event.pressed){
        SEND_STRING("git push");
        return MACRO( T(ENT), END );
      }
      break;
/*    case 3:
      if (record->event.pressed){
        layer_on(_CAPS);
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
      }
      break;
    case 4:
      if (record->event.pressed){
        layer_off(_CAPS);
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
      }*/
      break;
  }
  return MACRO_NONE;
};
 
