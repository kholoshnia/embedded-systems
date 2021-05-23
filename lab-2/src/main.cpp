#include "hal.h"

#include "utils/switches.hpp"
#include "utils/animation.hpp"

const unsigned int delay = 500;
const unsigned int delay_delta = 200;

void TIM6_IRQ_Handler() {
  animation();
}

void TIM7_IRQ_Handler() {
  WRITE_REG(TIM6_ARR, delay + get_delay_number() * delay_delta);
}

int umain() {
  registerTIM6_IRQHandler(TIM6_IRQ_Handler);
  registerTIM7_IRQHandler(TIM7_IRQ_Handler);

  __enable_irq();

  WRITE_REG(TIM6_ARR, delay + get_delay_number() * delay_delta);
  WRITE_REG(TIM6_DIER, TIM_DIER_UIE);
  WRITE_REG(TIM6_PSC, 0);

  WRITE_REG(TIM7_ARR, 100);
  WRITE_REG(TIM7_DIER, TIM_DIER_UIE);
  WRITE_REG(TIM7_PSC, 0);

  WRITE_REG(TIM6_CR1, TIM_CR1_CEN);
  WRITE_REG(TIM7_CR1, TIM_CR1_CEN);

  return 0;
}