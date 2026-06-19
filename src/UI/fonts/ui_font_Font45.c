/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font C:/Users/ASUS/Desktop/lvgl/assets/STFANGSO.TTF -o C:/Users/ASUS/Desktop/lvgl/assets\ui_font_Font45.c --format lvgl -r 0x20-0x7f --symbols 双闪左转右转 --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FONT45
#define UI_FONT_FONT45 1
#endif

#if UI_FONT_FONT45

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0x60,

    /* U+0022 "\"" */
    0x99, 0x99, 0x90,

    /* U+0023 "#" */
    0x11, 0x11, 0x3f, 0xe4, 0x42, 0x22, 0x11, 0x9,
    0xff, 0x44, 0x22, 0x11, 0x0,

    /* U+0024 "$" */
    0x31, 0xeb, 0x6c, 0xb1, 0xc3, 0xe, 0x34, 0xdb,
    0x5e, 0x30, 0xc0,

    /* U+0025 "%" */
    0x60, 0x89, 0x8, 0x91, 0x9, 0x20, 0x92, 0x6,
    0x46, 0x4, 0x90, 0x89, 0x8, 0x91, 0x9, 0x20,
    0xa2, 0x4,

    /* U+0026 "&" */
    0x18, 0x4, 0x80, 0x90, 0x1c, 0x1, 0x8c, 0xd1,
    0x23, 0x44, 0x38, 0x83, 0x18, 0xa1, 0xe3, 0x80,

    /* U+0027 "'" */
    0xf8,

    /* U+0028 "(" */
    0x2, 0x24, 0x48, 0x88, 0x88, 0x88, 0x44, 0x21,

    /* U+0029 ")" */
    0x8, 0x42, 0x21, 0x11, 0x11, 0x12, 0x24, 0x48,

    /* U+002A "*" */
    0x10, 0x21, 0x51, 0xc7, 0xc2, 0x4, 0x0,

    /* U+002B "+" */
    0x8, 0x4, 0x2, 0x1, 0xf, 0xf8, 0x40, 0x20,
    0x10, 0x8, 0x0,

    /* U+002C "," */
    0xd8,

    /* U+002D "-" */
    0xe0,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x4, 0x10, 0x82, 0x8, 0x41, 0x8, 0x20, 0x84,
    0x10, 0x42, 0x8, 0x0,

    /* U+0030 "0" */
    0x33, 0x28, 0x61, 0x86, 0x18, 0x61, 0x85, 0x23,
    0x0,

    /* U+0031 "1" */
    0x26, 0xa2, 0x22, 0x22, 0x22, 0x20,

    /* U+0032 "2" */
    0x39, 0x38, 0x41, 0x4, 0x21, 0x8, 0x41, 0x1f,
    0xc0,

    /* U+0033 "3" */
    0x72, 0x20, 0x84, 0x38, 0x30, 0x41, 0x4, 0x2f,
    0x0,

    /* U+0034 "4" */
    0x8, 0x10, 0x61, 0x44, 0x89, 0x22, 0x7f, 0x8,
    0x10, 0x20,

    /* U+0035 "5" */
    0x79, 0x4, 0x10, 0x79, 0x30, 0x41, 0x4, 0x2f,
    0x0,

    /* U+0036 "6" */
    0x18, 0x84, 0x10, 0x8a, 0x18, 0x61, 0x85, 0x13,
    0x80,

    /* U+0037 "7" */
    0xfc, 0x10, 0x82, 0x8, 0x41, 0x4, 0x20, 0x82,
    0x0,

    /* U+0038 "8" */
    0x72, 0x28, 0xa2, 0x51, 0xc8, 0xe1, 0x86, 0x17,
    0x80,

    /* U+0039 "9" */
    0x72, 0x28, 0x61, 0x86, 0x16, 0x42, 0x8, 0x46,
    0x0,

    /* U+003A ":" */
    0xc6,

    /* U+003B ";" */
    0xa0, 0xd, 0x80,

    /* U+003C "<" */
    0x0, 0x81, 0x83, 0x6, 0xc, 0x3, 0x0, 0x60,
    0xe, 0x0, 0x80,

    /* U+003D "=" */
    0xff, 0x80, 0x0, 0x0, 0xf, 0xf8,

    /* U+003E ">" */
    0x0, 0x70, 0x6, 0x0, 0xc0, 0x18, 0x30, 0x60,
    0xc0, 0x80, 0x0,

    /* U+003F "?" */
    0x60, 0x82, 0x10, 0xb9, 0x8, 0x2, 0x10,

    /* U+0040 "@" */
    0x7, 0xc0, 0x60, 0x82, 0x1, 0x10, 0x5a, 0x46,
    0xca, 0x21, 0x28, 0x84, 0xa4, 0x22, 0x91, 0x92,
    0x4a, 0x48, 0xce, 0x90, 0x2, 0x40, 0x10, 0xc0,
    0x80, 0xfc, 0x0,

    /* U+0041 "A" */
    0x4, 0x0, 0x80, 0x28, 0x9, 0x1, 0x20, 0x3e,
    0x8, 0x41, 0x8, 0x20, 0x88, 0x11, 0x83, 0x0,

    /* U+0042 "B" */
    0x7e, 0x10, 0x88, 0x44, 0x43, 0xe1, 0x8, 0x82,
    0x41, 0x20, 0x90, 0x9f, 0x80,

    /* U+0043 "C" */
    0x1f, 0x30, 0x90, 0x10, 0x8, 0x4, 0x2, 0x1,
    0x0, 0x40, 0xa0, 0x4f, 0xc0,

    /* U+0044 "D" */
    0x7f, 0x4, 0x18, 0x81, 0x10, 0x12, 0x2, 0x40,
    0x48, 0x9, 0x1, 0x20, 0x44, 0x19, 0xfc, 0x0,

    /* U+0045 "E" */
    0x7f, 0x88, 0x22, 0x0, 0x80, 0x21, 0xf, 0xc2,
    0x10, 0x80, 0x20, 0x48, 0x17, 0xfc,

    /* U+0046 "F" */
    0x7f, 0x41, 0x41, 0x42, 0x42, 0x7e, 0x42, 0x40,
    0x40, 0x40, 0x60,

    /* U+0047 "G" */
    0xf, 0x83, 0x4, 0x40, 0x8, 0x0, 0x80, 0x8,
    0x0, 0x81, 0xf8, 0x4, 0x40, 0x42, 0x4, 0x1f,
    0x80,

    /* U+0048 "H" */
    0x30, 0x42, 0x4, 0x20, 0x42, 0x4, 0x20, 0x43,
    0xfc, 0x20, 0x42, 0x4, 0x20, 0x42, 0x4, 0x60,
    0x60,

    /* U+0049 "I" */
    0x71, 0x8, 0x42, 0x10, 0x84, 0x21, 0x1c,

    /* U+004A "J" */
    0x18, 0x20, 0x82, 0x8, 0x20, 0x82, 0x8, 0x20,
    0x82, 0x10, 0x46, 0x0,

    /* U+004B "K" */
    0x41, 0x88, 0x41, 0x10, 0x24, 0x5, 0x0, 0xe0,
    0x16, 0x2, 0x20, 0x43, 0x8, 0x31, 0x7, 0x0,

    /* U+004C "L" */
    0x70, 0x10, 0x8, 0x4, 0x2, 0x1, 0x0, 0x80,
    0x40, 0x20, 0x10, 0x5f, 0xe0,

    /* U+004D "M" */
    0x30, 0x31, 0x81, 0xa, 0x18, 0x51, 0x42, 0x8a,
    0x12, 0x50, 0x94, 0x84, 0xe4, 0x23, 0x21, 0x11,
    0x1c, 0xc,

    /* U+004E "N" */
    0x60, 0x63, 0x2, 0x38, 0x22, 0x82, 0x24, 0x22,
    0x22, 0x21, 0x22, 0xa, 0x20, 0xa2, 0x6, 0x70,
    0x20,

    /* U+004F "O" */
    0x1f, 0xc, 0x11, 0x1, 0x40, 0x18, 0x3, 0x0,
    0x60, 0xc, 0x1, 0x40, 0x44, 0x10, 0x7c, 0x0,

    /* U+0050 "P" */
    0x7e, 0x23, 0x21, 0x21, 0x21, 0x22, 0x2c, 0x20,
    0x20, 0x20, 0x30,

    /* U+0051 "Q" */
    0x1f, 0x4, 0x11, 0x1, 0x40, 0x18, 0x3, 0x0,
    0x60, 0xc, 0x1, 0x80, 0x48, 0x8, 0x82, 0xf,
    0x80, 0x30, 0x3, 0x0, 0x18,

    /* U+0052 "R" */
    0x7e, 0x8, 0xc2, 0x10, 0x84, 0x22, 0xf, 0x2,
    0x60, 0x88, 0x23, 0x8, 0x47, 0x1c,

    /* U+0053 "S" */
    0x7a, 0x28, 0x30, 0x60, 0xe1, 0xc1, 0x6, 0x1f,
    0x80,

    /* U+0054 "T" */
    0xff, 0xe2, 0x18, 0x84, 0x20, 0x8, 0x2, 0x0,
    0x80, 0x20, 0x8, 0x2, 0x1, 0xc0,

    /* U+0055 "U" */
    0x70, 0xc4, 0x8, 0x81, 0x10, 0x22, 0x4, 0x40,
    0x88, 0x11, 0x2, 0x20, 0x44, 0x10, 0x3c, 0x0,

    /* U+0056 "V" */
    0x70, 0xc4, 0x10, 0x82, 0x18, 0x41, 0x10, 0x32,
    0x2, 0x80, 0x50, 0xe, 0x0, 0x80, 0x10, 0x0,

    /* U+0057 "W" */
    0x46, 0x45, 0x89, 0x22, 0x28, 0x88, 0xe2, 0x31,
    0x10, 0x46, 0x41, 0xa9, 0x2, 0xa8, 0xc, 0x60,
    0x31, 0x0, 0x44, 0x0,

    /* U+0058 "X" */
    0x70, 0xc6, 0x10, 0x44, 0xd, 0x0, 0xe0, 0x8,
    0x1, 0x80, 0xd8, 0x11, 0x4, 0x11, 0xc7, 0x0,

    /* U+0059 "Y" */
    0x60, 0xc4, 0x10, 0xc4, 0xc, 0x80, 0xa0, 0x18,
    0x1, 0x0, 0x20, 0x4, 0x0, 0x80, 0x38, 0x0,

    /* U+005A "Z" */
    0x7f, 0x41, 0x80, 0x80, 0x80, 0xc0, 0x40, 0x40,
    0x60, 0x20, 0x20, 0x7f, 0xe0,

    /* U+005B "[" */
    0xd2, 0x49, 0x24, 0x92, 0x49, 0x38,

    /* U+005C "\\" */
    0x82, 0x4, 0x10, 0x40, 0x82, 0x8, 0x10, 0x40,
    0x82, 0x8, 0x10, 0x40,

    /* U+005D "]" */
    0x64, 0x92, 0x49, 0x24, 0x92, 0x78,

    /* U+005E "^" */
    0x0, 0x61, 0x24, 0x48, 0x40,

    /* U+005F "_" */
    0xff,

    /* U+0060 "`" */
    0x88, 0x80,

    /* U+0061 "a" */
    0x74, 0xa4, 0x6d, 0x4b, 0xe0,

    /* U+0062 "b" */
    0x1, 0x81, 0x2, 0x4, 0xf, 0x91, 0xa1, 0x42,
    0x85, 0x13, 0xc0,

    /* U+0063 "c" */
    0x7a, 0x28, 0x20, 0x81, 0x17, 0x80,

    /* U+0064 "d" */
    0xc, 0x8, 0x10, 0x23, 0xd8, 0xa1, 0x42, 0x85,
    0x89, 0xd8,

    /* U+0065 "e" */
    0x74, 0x7f, 0x8, 0x61, 0xe0,

    /* U+0066 "f" */
    0x39, 0x4, 0x10, 0xf1, 0x4, 0x10, 0x41, 0x6,
    0x0,

    /* U+0067 "g" */
    0x7f, 0xa, 0x14, 0x47, 0x18, 0x1f, 0x21, 0x83,
    0x5, 0xf0,

    /* U+0068 "h" */
    0x40, 0x81, 0x2, 0x5, 0x8c, 0x91, 0x22, 0x44,
    0x89, 0x90,

    /* U+0069 "i" */
    0x40, 0x4, 0x92, 0x49, 0x0,

    /* U+006A "j" */
    0x50, 0x55, 0x55, 0x58,

    /* U+006B "k" */
    0x40, 0x81, 0x2, 0x4, 0xc9, 0x14, 0x38, 0x58,
    0x91, 0x10,

    /* U+006C "l" */
    0xc9, 0x24, 0x92, 0x49, 0x0,

    /* U+006D "m" */
    0x0, 0xb, 0x31, 0x99, 0x22, 0x24, 0x44, 0x88,
    0x91, 0x12, 0x22,

    /* U+006E "n" */
    0x0, 0xb3, 0x92, 0x24, 0x48, 0x91, 0x22,

    /* U+006F "o" */
    0x39, 0xa, 0xc, 0x18, 0x30, 0x9e, 0x0,

    /* U+0070 "p" */
    0x41, 0xb9, 0x9a, 0x14, 0x28, 0x51, 0x34, 0x50,
    0x81, 0x3, 0x0,

    /* U+0071 "q" */
    0x0, 0xfa, 0x14, 0x28, 0x50, 0x91, 0x3e, 0x4,
    0x8, 0x10, 0x20,

    /* U+0072 "r" */
    0x2, 0xb8, 0x84, 0x21, 0xc,

    /* U+0073 "s" */
    0x68, 0xc6, 0x19, 0xe0,

    /* U+0074 "t" */
    0x4, 0xf4, 0x44, 0x44, 0x70,

    /* U+0075 "u" */
    0x44, 0x89, 0x12, 0x24, 0x48, 0x8f, 0x80,

    /* U+0076 "v" */
    0x66, 0x64, 0x24, 0x28, 0x18, 0x10, 0x10,

    /* U+0077 "w" */
    0x4c, 0x48, 0x90, 0x92, 0x13, 0x43, 0xb0, 0x36,
    0x4, 0x80,

    /* U+0078 "x" */
    0x64, 0x50, 0xc0, 0x82, 0x88, 0x99, 0x80,

    /* U+0079 "y" */
    0x64, 0x48, 0x91, 0x41, 0x83, 0x4, 0x8, 0x20,
    0x41, 0x80,

    /* U+007A "z" */
    0x1, 0xf8, 0x84, 0x30, 0x84, 0x7f,

    /* U+007B "{" */
    0xd, 0x24, 0x94, 0x91, 0x24, 0x93,

    /* U+007C "|" */
    0xff, 0xfe,

    /* U+007D "}" */
    0x11, 0x24, 0x92, 0x29, 0x24, 0x94,

    /* U+007E "~" */
    0x60, 0x4c, 0x81, 0xc0,

    /* U+007F "" */
    0x0,

    /* U+53CC "双" */
    0x2, 0x11, 0xff, 0xc0, 0x42, 0x1, 0x48, 0x15,
    0x20, 0x63, 0x0, 0x8c, 0x5, 0x30, 0x14, 0xc0,
    0x84, 0x84, 0x22, 0x21, 0x7, 0x0, 0x0,

    /* U+53F3 "右" */
    0x0, 0x0, 0x2, 0x0, 0x10, 0x0, 0x40, 0x1,
    0x3d, 0xfb, 0x0, 0x40, 0x1, 0x0, 0x8, 0x70,
    0x5e, 0x42, 0x42, 0x11, 0x8, 0x4, 0x20, 0x1f,
    0x0, 0x40, 0x0,

    /* U+5DE6 "左" */
    0x1, 0x0, 0x4, 0x0, 0x20, 0x0, 0x82, 0x3f,
    0xf0, 0x10, 0x0, 0x40, 0x2, 0x4, 0xf, 0xe0,
    0x42, 0x1, 0x8, 0x8, 0x20, 0x20, 0x8d, 0x7f,
    0xf1, 0x0, 0x0,

    /* U+8F6C "转" */
    0x0, 0x40, 0x41, 0x1, 0x4, 0x5, 0x14, 0x68,
    0xa0, 0xa2, 0x2, 0x8f, 0x97, 0x60, 0x29, 0x0,
    0x37, 0xc3, 0x82, 0x12, 0x8, 0x8, 0x40, 0x20,
    0x80, 0x81, 0x0,

    /* U+95EA "闪" */
    0x0, 0x18, 0x12, 0xfe, 0x1, 0x80, 0x61, 0x18,
    0x86, 0x21, 0x96, 0x64, 0x5a, 0x6, 0x1, 0x80,
    0x60, 0x30, 0x8
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 64, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 56, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 104, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 6, .adv_w = 171, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 19, .adv_w = 115, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 30, .adv_w = 211, .box_w = 12, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 48, .adv_w = 187, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 64, .adv_w = 45, .box_w = 1, .box_h = 5, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 65, .adv_w = 75, .box_w = 4, .box_h = 16, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 73, .adv_w = 75, .box_w = 4, .box_h = 16, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 81, .adv_w = 109, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 88, .adv_w = 171, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 99, .adv_w = 56, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 100, .adv_w = 80, .box_w = 3, .box_h = 1, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 101, .adv_w = 56, .box_w = 1, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 102, .adv_w = 128, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 114, .adv_w = 120, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 120, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 129, .adv_w = 120, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 138, .adv_w = 120, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 147, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 157, .adv_w = 120, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 166, .adv_w = 120, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 175, .adv_w = 120, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 184, .adv_w = 120, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 193, .adv_w = 120, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 202, .adv_w = 56, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 56, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 206, .adv_w = 171, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 217, .adv_w = 171, .box_w = 9, .box_h = 5, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 223, .adv_w = 171, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 234, .adv_w = 93, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 241, .adv_w = 235, .box_w = 14, .box_h = 15, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 268, .adv_w = 173, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 284, .adv_w = 157, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 297, .adv_w = 163, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 310, .adv_w = 197, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 326, .adv_w = 168, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 340, .adv_w = 144, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 351, .adv_w = 197, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 368, .adv_w = 195, .box_w = 12, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 385, .adv_w = 91, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 392, .adv_w = 85, .box_w = 6, .box_h = 15, .ofs_x = -2, .ofs_y = -4},
    {.bitmap_index = 404, .adv_w = 189, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 420, .adv_w = 147, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 433, .adv_w = 213, .box_w = 13, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 451, .adv_w = 197, .box_w = 12, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 468, .adv_w = 200, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 484, .adv_w = 144, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 495, .adv_w = 197, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 516, .adv_w = 160, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 530, .adv_w = 123, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 539, .adv_w = 157, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 553, .adv_w = 181, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 569, .adv_w = 173, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 585, .adv_w = 227, .box_w = 14, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 605, .adv_w = 179, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 621, .adv_w = 168, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 637, .adv_w = 168, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 650, .adv_w = 69, .box_w = 3, .box_h = 15, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 656, .adv_w = 128, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 668, .adv_w = 69, .box_w = 3, .box_h = 15, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 674, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 679, .adv_w = 128, .box_w = 8, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 680, .adv_w = 85, .box_w = 3, .box_h = 3, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 682, .adv_w = 104, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 687, .adv_w = 131, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 698, .adv_w = 107, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 704, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 714, .adv_w = 107, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 719, .adv_w = 83, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 728, .adv_w = 115, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 738, .adv_w = 131, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 748, .adv_w = 59, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 753, .adv_w = 59, .box_w = 2, .box_h = 15, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 757, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 767, .adv_w = 59, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 772, .adv_w = 197, .box_w = 11, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 783, .adv_w = 131, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 790, .adv_w = 131, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 797, .adv_w = 131, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 808, .adv_w = 125, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 819, .adv_w = 85, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 824, .adv_w = 93, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 828, .adv_w = 75, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 833, .adv_w = 125, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 840, .adv_w = 120, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 847, .adv_w = 171, .box_w = 11, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 857, .adv_w = 117, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 864, .adv_w = 107, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 874, .adv_w = 109, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 880, .adv_w = 123, .box_w = 3, .box_h = 16, .ofs_x = 3, .ofs_y = -4},
    {.bitmap_index = 886, .adv_w = 128, .box_w = 1, .box_h = 15, .ofs_x = 4, .ofs_y = -4},
    {.bitmap_index = 888, .adv_w = 123, .box_w = 3, .box_h = 16, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 894, .adv_w = 171, .box_w = 9, .box_h = 3, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 898, .adv_w = 192, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 899, .adv_w = 256, .box_w = 14, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 922, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 949, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 976, .adv_w = 256, .box_w = 14, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1003, .adv_w = 256, .box_w = 10, .box_h = 15, .ofs_x = 3, .ofs_y = -3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x27, 0xa1a, 0x3ba0, 0x421e
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 96, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 21452, .range_length = 16927, .glyph_id_start = 97,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 5, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_Font45 = {
#else
lv_font_t ui_font_Font45 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_FONT45*/

