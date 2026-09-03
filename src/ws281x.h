/**
 * @file ws281x.h
 * @brief Driver for the WS281X addressable LED controllers.
 * Uses PIO blocks from the RP2040 and RP2350 MCUs.
 *
 * @author Leo Walker
 */

#ifndef _WS281X_H_
#define _WS281X_H_

#include <stdint.h>

#include "colour.h"

/**
 * @brief Represents the PIO blocks
 */
typedef enum ws281x_pio_hardware : uint8_t
{
    WS281X_PIO_0,
    WS281X_PIO_1,
    WS281X_PIO_2
} ws281x_pio_hardware_t;

/**
 *
 */
typedef struct ws281x_config
{
    ws281x_pio_hardware_t hardware_block;
    uint8_t state_machine;
    uint16_t led_count;
    uint8_t gpio_pin;
} ws281x_config_t;

/**
 * @brief Opaque instance of a WS281x LED strip.
 */
typedef struct ws281x_impl *WS281X;

/**
 * @brief Initialise a LED strip.
 *
 * @param config The configuration for the strip.
 *
 * @return A pointer to a new WS281x instance, or NULL if failed.
 */
WS281X ws281x_init(ws281x_config_t *config);

/**
 * @brief Destroy a WS281x instance.
 *
 * @param dev The instance pointer.
 */
void ws281x_destroy(WS281X dev);

/**
 * @brief Update the LED strip with the current pattern.
 */
void ws281x_update(WS281X dev);

/**
 * @brief Set the colour of a single LED.
 *
 * @param dev The ws281x instance.
 * @param led_offset The index of the LED along the strip.
 * @param colour The colour to set the LED to.
 *
 * @note Call ws281x_update() to see changes made with these functions.
 */
void ws281x_set_led(WS281X dev, uint16_t led_offset, const colour_t colour);

/**
 *
 */
void ws281x_set_all(WS281X dev, const colour_t colour);

#endif /* _WS281X_H_ */