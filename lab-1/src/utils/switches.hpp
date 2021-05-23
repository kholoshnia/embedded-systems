#ifndef SWITCHES_HPP
#define SWITCHES_HPP

#include "hal.h"

#include "equipment.hpp"
#include "processor.hpp"

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

void match() {
  yellow_only();

  GPIO_PinState pin_state;
  for (unsigned int sw = 0; sw < switch_number; ++sw) {
    pin_state = HAL_GPIO_ReadPin(GPIOE, switch_list[sw]);
    HAL_GPIO_WritePin(GPIOD, led_list[sw], pin_state);
  }
}

#endif // SWITCHES_HPP
