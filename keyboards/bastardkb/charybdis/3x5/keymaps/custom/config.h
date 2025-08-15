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