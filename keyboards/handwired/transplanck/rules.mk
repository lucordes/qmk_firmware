# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = caterina
ENCODER_ENABLE = no
EXTRAKEY_ENABLE = yes      # Audio control and System control


EXTRAKEY_ENABLE = yes
    MOUSEKEY_ENABLE=yes
TAP_DANCE_ENABLE = yes
CONSOLE_ENABLE=no

#EXTRAFLAGS += -flto

DEBOUNCE_DIR:= $(QUANTUM_DIR)/debounce
#DEBOUNCE_TYPE?= sym_defer_g
DEBOUNCE_TYPE?= sym_g
ifneq ($(strip $(DEBOUNCE_TYPE)), custom)d
    QUANTUM_SRC += $(DEBOUNCE_DIR)/$(strip $(DEBOUNCE_TYPE)).c
endif
AUDIO_ENABLE = yes
BLUETOOTH = no
NKRO_ENABLE=yes

