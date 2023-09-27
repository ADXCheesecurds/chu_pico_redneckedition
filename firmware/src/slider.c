/*
 * Chu Pico Silder Keys
 * WHowe <github.com/whowechina>
 * 
 * MPR121 CapSense based Keys
 */

#include "slider.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bsp/board.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"

#include "board_defs.h"

#include "config.h"
#include "mpr121.h"

#define MPR121_ADDR 0x5A

static uint16_t baseline[36];
static int16_t error[36];
static uint16_t readout[36];
static bool touched[36];
static uint16_t touch[3];

void slider_init()
{
    i2c_init(I2C_PORT, I2C_FREQ);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    
    for (int m = 0; m < 3; m++) {
        mpr121_init(MPR121_ADDR + m);
    }
    slider_update_config();
}

void slider_update()
{
    touch[0] = mpr121_touched(MPR121_ADDR);
    touch[1] = mpr121_touched(MPR121_ADDR + 1);
    touch[2] = mpr121_touched(MPR121_ADDR + 2);
}

const uint16_t *slider_raw()
{
    mpr121_raw(MPR121_ADDR, readout, 12);
    mpr121_raw(MPR121_ADDR + 1, readout + 12, 12);
    mpr121_raw(MPR121_ADDR + 2, readout + 24, 12);
    return readout;
}

bool slider_touched(unsigned key)
{
    if (key >= 32) {
        return 0;
    }
    return touch[key / 12] & (1 << (key % 12));
}

void slider_update_config()
{
    for (int m = 0; m < 3; m++) {
        mpr121_debounce(MPR121_ADDR + m, chu_cfg->sense.debounce_touch,
                                         chu_cfg->sense.debounce_release);
        mpr121_sense(MPR121_ADDR + m, chu_cfg->sense.global, chu_cfg->sense.keys + m * 12);
        mpr121_filter(MPR121_ADDR + m, chu_cfg->sense.filter & 0x0f,
                                       (chu_cfg->sense.filter >> 4) & 0x0f);
    }
}
