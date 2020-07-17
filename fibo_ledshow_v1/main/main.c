#include <stdio.h>
#include <string.h>
#include <driver/gpio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define PIN 5

int fib(int n)
{
  if (n <= 1)
    return n;
  return fib(n - 1) + fib(n - 2);
}

void app_main(void)
{
  gpio_pad_select_gpio(PIN);
  gpio_set_direction(PIN, GPIO_MODE_OUTPUT);
  int isOn = 0;
  int c, n;
  while (1)
  {
    printf("started\n");
    c = 10;
    n = fib(c);
    for (int i = 0; i <= n; ++i)
    {
      isOn = !isOn;
      gpio_set_level(PIN, isOn);
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      printf("%d\n", i);
    }
    printf("Done\n");
    vTaskDelay(5000 / portTICK_PERIOD_MS);
  }
}
