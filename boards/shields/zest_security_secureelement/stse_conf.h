/*
 * Copyright (c) 2026, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef SHIELD_STSE_CONF_H
#define SHIELD_STSE_CONF_H

#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define STSE_CONF_STSAFE_A_SUPPORT

#ifdef CONFIG_STSE_USE_RSP_POLLING
#define STSE_USE_RSP_POLLING
#define STSE_MAX_POLLING_RETRY      CONFIG_STSE_MAX_POLLING_RETRY
#define STSE_FIRST_POLLING_INTERVAL CONFIG_STSE_FIRST_POLLING_INTERVAL
#define STSE_POLLING_RETRY_INTERVAL CONFIG_STSE_POLLING_RETRY_INTERVAL
#endif /* CONFIG_STSE_USE_RSP_POLLING */

#define ZEPHYR_USER_NODE DT_PATH(zephyr_user)
extern const struct gpio_dt_spec stsafereset;

#endif /* STSE_CONF_H */
