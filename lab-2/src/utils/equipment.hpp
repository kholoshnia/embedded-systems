#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP

#include "hal.h"

const unsigned int led_number = 8;
const unsigned int led_list[led_number] = {
    GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6,
    GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_11, GPIO_PIN_12
};

const unsigned int switch_number = 4;
const unsigned int switch_list[switch_number] = {
    GPIO_PIN_4, GPIO_PIN_8, GPIO_PIN_10, GPIO_PIN_12
};

#endif // EQUIPMENT_HPP
