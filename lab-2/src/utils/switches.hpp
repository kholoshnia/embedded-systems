#ifndef SWITCHES_HPP
#define SWITCHES_HPP

#include "hal.h"
#include <iostream>

#include "equipment.hpp"

unsigned int get_switches_state() {
  unsigned int switches_state = 0;

  GPIO_PinState pin_state;
  for (unsigned int sw = 0; sw < switch_number; ++sw) {
    switches_state *= 10;
    pin_state = HAL_GPIO_ReadPin(GPIOE, switch_list[sw]);

    if (pin_state == GPIO_PIN_SET) {
      switches_state++;
    }
  }

  return switches_state;
}

unsigned int get_delay_number() {
  switch (get_switches_state()) {
    case 0:return 0;
    case 1:return 1;
    case 10:return 2;
    case 11:return 3;
    case 100:return 4;
    case 101:return 5;
    case 110:return 6;
    case 111:return 7;
    case 1000:return 8;
  }
}

#endif // SWITCHES_HPP
