#include <stdio.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define PIN 5

void app_main(void)
{
  // printf("Hello world!\n");
  gpio_pad_select_gpio(PIN);
  gpio_set_direction(PIN, GPIO_MODE_OUTPUT);
  int isOn = 0;
  while (1)
  {
    /* code */
    isOn = !isOn;
    gpio_set_level(PIN, isOn);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
