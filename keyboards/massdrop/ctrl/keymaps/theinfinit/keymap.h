#include QMK_KEYBOARD_H

#include <print.h>
#include <string.h>

#define IGNORE_MOD_TAP_INTERRUPT

// These are just to make it neater to use builtin HSV values in the keymap
#define RED {HSV_RED}
#define CORAL {HSV_CORAL}
#define ORANGE {HSV_ORANGE}
#define GOLDEN {HSV_GOLDENROD}
#define GOLD {HSV_GOLD}
#define YELLOW {HSV_YELLOW}
#define CHART {HSV_CHARTREUSE}
#define GREEN {HSV_GREEN}
#define SPRING {HSV_SPRINGGREEN}
#define TURQ {HSV_TURQUOISE}
#define TEAL {HSV_TEAL}
#define CYAN {HSV_CYAN}
#define AZURE {HSV_AZURE}
#define BLUE {HSV_BLUE}
#define PURPLE {HSV_PURPLE}
#define MAGENT {HSV_MAGENTA}
#define PINK {HSV_PINK}

bool rgb_enabled_flag;          // Current LED state flag. If false then LED is off.

enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE,      //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,                   //USB Toggle Automatic GCR control
    DBG_TOG,                    //DEBUG Toggle On / Off
    DBG_MTRX,                   //DEBUG Toggle Matrix Prints
    DBG_KBD,                    //DEBUG Toggle Keyboard Prints
    DBG_MOU,                    //DEBUG Toggle Mouse Prints
    MD_BOOT,                    //Restart into bootloader after hold timeout

    VIM_G,
    BSPC_BOF,                   // Backspace on tap / Ctrl + Home (BOF) with shift 
    C_BSPC_EOF,                 // Ctrl + Backspace on tap / Ctrl + End (EOF) with shift
    NEW_LINE,                   // Create new line below cursor (with Shift—above cursor)
    YANK,                       // Ctrl + Ins (Copy) on tap / Copy to the EOL with shift
    COPY_CUT,                   // Ctrl + x (Cut) on tap / Cut current line with shift
};

enum layout_names {
    _KL=0,                      // Keys Layout: The main keyboard layout that has all the characters
    _ML,
    _NL,                        // Numbers Layout
    _SL,                        // Symbols Layout
    _NSL,                       // Symbols from number row
    _FL,                        // Function Layout: The function key activated layout with default functions and some added ones
};
