OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABL = yes      # Enable keyboard RGB underglow
WPM_ENABLE = yes

# reduce firmware size
MOUSEKEY_ENABLE = no
TAP_DANCE_ENABLE = no
STENO_ENABLE = no
BOOTMAGIC_ENABLE = no
TERMINAL_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
KEY_LOCK_ENABLE = no
AUDIO_ENABLE = no
CONSOLE_ENABLE = no
VELOCIKEY_ENABLE = no
COMMAND_ENABLE = no
NO_USB_STARTUP_CHECK = no

EXTRAFLAGS += -flto
