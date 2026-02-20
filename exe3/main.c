#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_RED = 4;
const int LED_PIN_GREEN = 6;
const int BTN_PIN_RED = 28;
const int BTN_PIN_GREEN = 26;

int main() {
  stdio_init_all();

  int led_state_red = 0;
  int led_state_green = 0;

  gpio_init(LED_PIN_RED);
  gpio_set_dir(LED_PIN_RED, GPIO_OUT); 

  gpio_init(LED_PIN_GREEN);
  gpio_set_dir(LED_PIN_GREEN, GPIO_OUT); 

  gpio_init(BTN_PIN_RED);
  gpio_set_dir(BTN_PIN_RED, GPIO_IN);
  gpio_pull_up(BTN_PIN_RED);

  gpio_init(BTN_PIN_GREEN);
  gpio_set_dir(BTN_PIN_GREEN, GPIO_IN);
  gpio_pull_up(BTN_PIN_GREEN);

  gpio_put(LED_PIN_RED, led_state_red);
  gpio_put(LED_PIN_GREEN, led_state_green);


  while (true) {
    if (!gpio_get(BTN_PIN_RED)){
      led_state_red = !led_state_red;

      gpio_put(LED_PIN_RED, led_state_red);
      printf("botao vermelho! led: %d\n", led_state_red);

      while (!gpio_get(BTN_PIN_RED)){
        sleep_ms(10);
      }
    }

    if (!gpio_get(BTN_PIN_GREEN)){
      led_state_green = !led_state_green;

      gpio_put(LED_PIN_GREEN, led_state_green);
      printf("botao verde! led: %d\n", led_state_green);

      while (!gpio_get(BTN_PIN_GREEN)){
        sleep_ms(10);
      }
    }
    
  }
}