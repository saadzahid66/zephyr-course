#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#define RED_LED_NODE DT_ALIAS(ext_red_led)

static const struct gpio_dt_spec red_led = GPIO_DT_SPEC_GET(RED_LED_NODE, gpios);

int main()
{
    gpio_pin_configure_dt(&red_led, GPIO_OUTPUT_INACTIVE);

    while(1) {
        gpio_pin_toggle_dt(&red_led);
        k_msleep(CONFIG_LED_BLINK_TIME_MS);
    }

    return 0;

}