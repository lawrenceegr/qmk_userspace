VIA_ENABLE = yes

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360   # keep what already works

# Also compile the Cirque sources so we can call them directly.
SRC += drivers/sensors/cirque_pinnacle.c \
       drivers/sensors/cirque_pinnacle_i2c.c \
       drivers/sensors/cirque_pinnacle_gestures.c
