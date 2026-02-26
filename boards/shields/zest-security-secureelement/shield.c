/*
 * Copyright (c) 2026, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(stsafe_a1xx_shield);

#include "stselib.h"

int stsafe_a1xx_init(void) {
  int ret;
  const struct gpio_dt_spec stsafe_reset =
      GPIO_DT_SPEC_GET(ZEPHYR_USER_NODE, stsafereset_gpios);

  if (!gpio_is_ready_dt(&stsafe_reset)) {
    LOG_ERR("STSafe reset GPIO is not ready!");
    return -1;
  }

  if (gpio_pin_configure_dt(&stsafe_reset, GPIO_OUTPUT_ACTIVE) < 0) {
    LOG_ERR("Failed to configure STSafe reset GPIO!");

    return -1;
  }

  return 0;
}

SYS_INIT(stsafe_a1xx_init, POST_KERNEL,
         CONFIG_SHIELD_STSAFE_A1XX_INIT_PRIORITY);
