#include "macros.h"


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case EM_SMILE:
    if (record->event.pressed) {
      // do something
    }
    break;
  }
  return true;
}
