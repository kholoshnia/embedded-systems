#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "hal.h"

#include "equipment.hpp"
#include "processor.hpp"
#include "switches.hpp"

const unsigned int delay = 500;
const unsigned int frames = 12;

const unsigned int led_animation[frames][led_number] = {
    {1, 1, 1, 0, 0, 0, 1, 1},
    {0, 1, 1, 1, 0, 1, 1, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 1, 1, 1},
    {1, 1, 0, 0, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0},
};

void animate(const unsigned int &state) {
  green_only();

  GPIO_PinState pin_state;
  for (unsigned int frame = 0; frame < frames; ++frame) {
    for (unsigned int led = 0; led < led_number; ++led) {
      pin_state = led_animation[frame][led] == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET;
      HAL_GPIO_WritePin(GPIOD, led_list[led], pin_state);
    }

    HAL_Delay(delay);

    if (button_pressed()) {
      HAL_Delay(delay);
      red_only();

      while (true) {
        if (button_pressed() || get_switches_state() != state) {
          green_only();
          break;
        }
      }
    }

    if (get_switches_state() != state) {
      break;
    }
  }

  for (const unsigned int &led : led_list) {
    HAL_GPIO_WritePin(GPIOD, led, GPIO_PIN_RESET);
  }
}

#endif // ANIMATION_HPP
