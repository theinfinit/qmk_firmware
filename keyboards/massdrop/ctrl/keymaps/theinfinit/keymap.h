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
    NEW_LINE,                   // Create new line below cursor (with Shift—above)

    VIM_Y,                      // VIM Yank one shot layer. With Shift modifier copy to the EOL.
    COPY_ALL,                   // Select all text and copy
    COPY_WORD,                  // Select word, copy, deselect
    COPY_WORD_BACKWARDS,        // Select word backwards, copy, deselect
    COPY_LINE,                  // Select whole line, copy, deselect
    COPY_TO_EOL,                // Select from cursor to the end of line, copy, deselect
    COPY_TO_BOL,                // Select from cursor to the beginning of line, copy, deselect
    COPY_TWO_LINES_UP,          // Copy current line and one up 
    COPY_TWO_LINES_DOWN,        // Copy current line and one down

    VIM_D,                      // VIM Delete one shot layer. With Shift modifier delete to the EOL.
    DELETE_ALL,                 // Delete all text
    DELETE_WORD,                // Delete word forward
    DELETE_WORD_BACKWARDS,      // Delete word backwards
    DELETE_LINE,                // Delete current line
    DELETE_TO_EOL,              // Delete from cursor to the end of line
    DELETE_TO_BOL,              // Delete from cursor to the beginning of line
    DELETE_TWO_LINES_UP,        // Delete current line and one up
    DELETE_TWO_LINES_DOWN,      // Delete current line and one down

    VIM_C,                      // VIM Change one shot layer. With Shift modifier cut to the EOL.
    CUT_ALL,                    // Copy and delete all text
    CUT_WORD,                   // Copy and delete word forward
    CUT_WORD_BACKWARDS,         // Copy and delete word backwards
    CUT_LINE,                   // Copy and delete current line
    CUT_TO_EOL,                 // Copy and delete from cursor to the end of line
    CUT_TO_BOL,                 // Copy and delete from cursor to the beginning of line
    CUT_TWO_LINES_UP,           // Copy and delete current line and one up
    CUT_TWO_LINES_DOWN,         // Copy and delete current line and one down
};

enum layout_names {
    _KL=0,                      // Keys Layout: The main keyboard layout that has all the characters
    _ML,
    _NL,                        // Numbers Layout
    _SL,                        // Symbols Layout
    _NSL,                       // Symbols from number row
    _FL,                        // Function Layout: The function key activated layout with default functions and some added ones
    _LEADER,                    // Leader Key 
    _VIM_YANK,                  // VIM Yank Layout
    _VIM_DELETE,                // VIM Delete Layout
    _VIM_CHANGE,                // VIM Change Layout
};
