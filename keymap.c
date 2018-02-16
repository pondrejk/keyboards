// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _PLOVER 5
#define _NUMLAYER 7
#define _ADJUST 16

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwertz (SK)
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  |  "   |
 * |------+------+------+------+------+------+-------------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  /   | Bksp |
 * |------+------+------+------+------+------+------|------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |   N  |   M  |  ,?  |  .:  | -_   |  Ent |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Numer| Ctrl |  GUI | Alt  |Lower | sp   | sp   |Raise | Righ | Down |  Up  | Left |
 * `-----------------------------------------------------------------------------------'
 */

[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    S(KC_SCLN)},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,    KC_J,  KC_K,    KC_L,    KC_LCBR, KC_BSPC},
  {F(2),    KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, F(1)},
  {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC,  RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower (SK)
 * ,-----------------------------------------------------------------------------------.
 * |  °   |  ä   |   2  |  é   |   4  |   ť  |  6   |   ú  |   í  |   ô  |  ó   |      |
 * |------+------+------+------+------+------+------|------+------+------+------+------|
 * | Del  |  á   |   š  |  ď   |´ mod |ˇ mod |      |   (  |   )  |   ľ  |  \   | Del  |
 * |------+------+------+------+------+------+------|------+------+------+------+------|
 * |      |  ý   |      |  č   |  C-n | C-b  |  ň   |   [  |   ]  |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | pgdn | pgup |      |
 * `-----------------------------------------------------------------------------------'
 */

[_LOWER] = {
  {KC_TILD, KC_RBRC, KC_AT,   KC_0,    KC_DLR,     KC_5,      KC_6,    KC_LBRC,    KC_9,       KC_SCLN,    KC_RPRN,    RALT(KC_QUOT)},
  {KC_DEL,  KC_8,    KC_3,    _______, KC_EQL,     S(KC_EQL), _______, KC_RCBR,    KC_PIPE,    KC_2,       KC_NUBS,    KC_DEL},
  {_______, KC_7,    _______, KC_4,    LCTL(KC_N), LCTL(KC_B),   _______, RALT(KC_F), RALT(KC_G), RALT(KC_B), RALT(KC_N), _______},
  {_______, _______, _______, _______, _______,    _______,   _______, _______,    _______,    KC_PGDN,    KC_PGUP,    _______}
},


/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ;  |   +  |  |   | C-e  |   $  |   %  |   &  |   *  |   !  |   =  |   í  | '    |
 * |------+------+------+------+------+------+-------------+------+------+------+------|
 * | Del  |  C-a |  C-s | C-d  |      |      | Left | Down |  Up  | Left |   \  | Del  |
 * |------+------+------+------+------+------+------|------+------+------+------+------|
 * |      |  ~   |  #   | C-c  |  @   |  `   |  F12 |   ^  |  <   |   >  | Play |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ |      |
 * `-----------------------------------------------------------------------------------'
 */

[_RAISE] = {
  {KC_GRV,  KC_1,       S(KC_NUBS), LCTL(KC_E), RALT(KC_4), KC_UNDS,    RALT(KC_7), KC_PAST,    S(KC_QUOT),    KC_PEQL,      LCTL(KC_P), RALT(KC_QUOT)},
  {KC_DEL,  LCTL(KC_A), LCTL(KC_S), LCTL(KC_D), LCTL(KC_F), _______,    KC_LEFT,    KC_DOWN,    KC_UP,         KC_RGHT,      KC_NUBS,    KC_DEL},
  {_______, RALT(KC_A), RALT(KC_3), LCTL(KC_C), RALT(KC_V), RALT(KC_H), KC_F12,     RALT(KC_M), RALT(KC_COMM), RALT(KC_DOT), _______,    RALT(KC_H)},
  {_______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_MNXT,       KC_VOLD,      KC_VOLU,    KC_MPLY}
},

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |TogOut|   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = {
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */


[_ADJUST] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL },
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Numeric kayer (Backlit)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |  0   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |   4  |   5  |   6  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F6  |  F8  |  F9  |  F10 |  F11 |  F12 |      |   1  |   2  |   3  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |   0  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMLAYER] = {
  {_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_DLR,  KC_PERC, KC_CIRC, _______, _______},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_EXLM, KC_AT,   KC_HASH, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_RPRN, _______, _______, _______}
}
};

const uint16_t PROGMEM fn_actions[] = { // TODO
  /* Layer switching
  [1] = ACTION_LAYER_TAP_KEY(NAVIGATION_LAYER, KC_SCOLON),
  [2] = ACTION_LAYER_TAP_KEY(NAVIGATION_LAYER, KC_O),
  [3] = ACTION_LAYER_TAP_KEY(GUI_LAYER, KC_LBRACKET),
  [4] = ACTION_LAYER_TAP_KEY(GUI_LAYER, KC_RBRACKET),
  */

  // Modifiers
  [1] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT), // enter/right shift
  [2] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_RBRC), // left shift/(
//[3] = ACTION_MODS_TAP_KEY(BACKLIT, KC_F), // left shift/0
//[3] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_RCBR), // left alt/(
//[4] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ENT), // left ctrl/[
//[5] = ACTION_MODS_TAP_KEY(MOD_BACKLIT, KC_ENT), // backlit(numlayer)/{
//[2] = ACTION_MODS_TAP_KEY(LOWER, KC_SPC) //mysli si ze lower je ctrl
};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        layer_on(_NUMLAYER);
        update_tri_layer(_LOWER, _NUMLAYER, _ADJUST);
      } else {
        layer_off(_NUMLAYER);
        update_tri_layer(_LOWER, _NUMLAYER, _ADJUST);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_NOTE_ARRAY(tone_plover, false, 0);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_NUMLAYER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_plover_gb, false, 0);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
