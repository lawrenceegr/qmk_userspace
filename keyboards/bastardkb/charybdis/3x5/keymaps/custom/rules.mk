VIA_ENABLE = yes

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360   # keep what already works

# The Cirque trackpad is read in keymap.c: compile its driver and I2C.
I2C_DRIVER_REQUIRED = yes
SRC += drivers/sensors/cirque_pinnacle.c \
       drivers/sensors/cirque_pinnacle_i2c.c \
       drivers/sensors/cirque_pinnacle_gestures.c
