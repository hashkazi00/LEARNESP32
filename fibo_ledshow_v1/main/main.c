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
  char c = 0;
  while (c != '\n')
  {
    c = getchar();
    if (c != 0xff)
    {
      // str[strlen(str)] = c;
      printf("%c", c);
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }

  int n = (int)c;

  int isOn = 0;

  for (int i = 1; i <= n; i++)
  {
    printf("%d\n", i);

    int k = fib(i);

    printf("%d\n", k);

    for (int j = 0; j < k; j++)
    {
      printf("%d\n", j);
      isOn = 1;
      gpio_set_level(PIN, isOn);
      vTaskDelay(500 / portTICK_PERIOD_MS);

      gpio_set_level(PIN, 0);
    }

    vTaskDelay(5000 / portTICK_PERIOD_MS);
  }
}
