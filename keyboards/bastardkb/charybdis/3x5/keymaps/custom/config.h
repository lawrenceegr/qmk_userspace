#pragma once

#ifdef VIA_ENABLE
#    define DYNAMIC_KEYMAP_LAYER_COUNT 7
#endif // VIA_ENABLE

#ifndef __arm__
#    define NO_ACTION_ONESHOT
#endif // __arm__

/* Pointing device configuration */
#ifdef POINTING_DEVICE_ENABLE
// Enable combined pointing devices
#define POINTING_DEVICE_COMBINED

// Cirque Pinnacle trackpad settings
// The Cirque is read by the keymap, not as POINTING_DEVICE_DRIVER, so QMK
// doesn't set its I2C address or bus. 0x2A is the Pinnacle default.
#define CIRQUE_PINNACLE_ADDR 0x2A
// I2C1 on GP2 (SDA) / GP3 (SCL): change to the pins the trackpad is wired to.
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3
#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define CIRQUE_PINNACLE_TAP_ENABLE
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
#define CIRQUE_PINNACLE_CURVED_OVERLAY
#define POINTING_DEVICE_ROTATION_180

// PMW3360 settings (already configured)
#define PMW3360_CPI 1200  // Default CPI, can be adjusted
#define PMW3360_CPI_STEP 200

// Auto layer triggering
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif // POINTING_DEVICE_ENABLE