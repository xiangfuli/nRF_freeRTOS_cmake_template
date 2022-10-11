#include "main.hpp"

#define LED_PIN   41

void task_led_blinking(void *pvParameter) {
  nrf_gpio_cfg_output(LED_PIN);

  while(1) {
    NRFX_DELAY_US(1000 * 1000);
    nrf_gpio_pin_toggle(LED_PIN);
  }
}


int main() {

  xTaskCreate(
    task_led_blinking,
    "task_led_blinking",
    configMINIMAL_STACK_SIZE,
    NULL,
    configMAX_PRIORITIES, 
    NULL
  );

  vTaskStartScheduler();
  while(1) {}
}