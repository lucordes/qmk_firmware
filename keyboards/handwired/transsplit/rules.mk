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

# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
<<<<<<< HEAD
MOUSEKEY_ENABLE = yes       # Mouse keys
=======
MOUSEKEY_ENABLE = no       # Mouse keys
>>>>>>> 5e31a52667ff28b5f44d9f8b311e89fa3cb25787
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = yes            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
<<<<<<< HEAD
RGBLIGHT_ENABLE = yes        # Enable WS2812 RGB underlight.
API_SYSEX_ENABLE = no
SPLIT_KEYBOARD = yes
TAP_DANCE_ENABLE = yes
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend
UCIS_ENABLE = yes
LAYOUTS = ortho_4x12
EXTRAFLAGS += -flto
=======
BLUETOOTH_ENABLE = yes      # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = yes        # Enable WS2812 RGB underlight.
API_SYSEX_ENABLE = no

Bluetooth=RN42
SPLIT_KEYBOARD = yes
TAP_DANCE_ENABLE = yes

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend
OLED_DRIVER_ENABLE = yes
LAYOUTS = ortho_4x12
>>>>>>> 5e31a52667ff28b5f44d9f8b311e89fa3cb25787

