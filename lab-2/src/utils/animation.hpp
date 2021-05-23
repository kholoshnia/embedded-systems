#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "hal.h"

#include "equipment.hpp"
#include "switches.hpp"

const unsigned int frames = 10;

const unsigned int led_animation[frames][led_number] = {
    {1, 1, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 0},
    {0, 0, 0, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0},
    {0, 1, 1, 1, 0, 0, 0, 0},
};

int frame = 0;

void animation() {
  GPIO_PinState state;
  for (unsigned int led = 0; led < led_number; ++led) {
    state = led_animation[frame][led] == 0 ? GPIO_PIN_RESET : GPIO_PIN_SET;
    HAL_GPIO_WritePin(GPIOD, led_list[led], state);
  }

  frame++;
  if (frame == frames) {
    frame = 0;
  }
}

#endif // ANIMATION_HPP
