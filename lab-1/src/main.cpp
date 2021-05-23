#include "hal.h"

#include "utils/switches.hpp"
#include "utils/animation.hpp"

[[noreturn]] int umain() {
  const unsigned int state = 100; // 0x4

  while (true) {
    get_switches_state() == state
    ? animate(state)
    : match();
  }
}