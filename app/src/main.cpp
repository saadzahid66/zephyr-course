#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

static const gpio_dt_spec status_led = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);

int main(void)
{
    if (!gpio_is_ready_dt(&status_led)) {
        printk("LED GPIO is not ready\n");
        return 0;
    }

    int ret = gpio_pin_configure_dt(&status_led, GPIO_OUTPUT_INACTIVE);
    if (ret < 0) {
        printk("LED GPIO configure failed: %d\n", ret);
        return 0;
    }

    printk("Hello World!\n");

    while (true) {
        ret = gpio_pin_toggle_dt(&status_led);
        if (ret < 0) {
            printk("LED GPIO toggle failed: %d\n", ret);
            return 0;
        }
        k_sleep(K_SECONDS(1));
    }

}