/*******************************************************************************
 * Size: 40 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef LV_FONT_DOTS_40
#define LV_FONT_DOTS_40 1
#endif

#if LV_FONT_DOTS_40

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+002D "-" */
    0xee, 0xfd, 0xdf, 0xbb, 0x80,

    /* U+0030 "0" */
    0xe, 0xee, 0x1, 0xdd, 0xc0, 0x3b, 0xb8, 0x0,
    0x0, 0xe, 0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0,
    0x38, 0x0, 0x0, 0xe0, 0x0, 0xfc, 0x0, 0x1f,
    0x80, 0x3, 0x80, 0x0, 0xe, 0x0, 0xf, 0xc0,
    0x1, 0xf8, 0x0, 0x38, 0x0, 0x0, 0xe0, 0x0,
    0xfc, 0x0, 0x1f, 0x80, 0x3, 0x80, 0x0, 0xe,
    0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0, 0x38, 0x0,
    0x0, 0xe, 0xee, 0x1, 0xdd, 0xc0, 0x3b, 0xb8,
    0x0,

    /* U+0031 "1" */
    0xe, 0x1, 0xc0, 0x38, 0x0, 0xe, 0xe1, 0xdc,
    0x3b, 0x80, 0x0, 0xe, 0x1, 0xc0, 0x38, 0x0,
    0x0, 0xe0, 0x1c, 0x3, 0x80, 0x0, 0xe, 0x1,
    0xc0, 0x38, 0x0, 0x0, 0xe0, 0x1c, 0x3, 0x80,
    0x0, 0xee, 0xfd, 0xdf, 0xbb, 0x80,

    /* U+0032 "2" */
    0xe, 0xee, 0x1, 0xdd, 0xc0, 0x3b, 0xb8, 0x0,
    0x0, 0xe, 0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0,
    0x38, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x0, 0x1c,
    0x0, 0x3, 0x80, 0x0, 0x0, 0x0, 0xe0, 0x0,
    0x1c, 0x0, 0x3, 0x80, 0x0, 0x0, 0x0, 0xe0,
    0x0, 0x1c, 0x0, 0x3, 0x80, 0x0, 0x0, 0x0,
    0xe0, 0x0, 0x1c, 0x0, 0x3, 0x80, 0x0, 0x0,
    0x0, 0xee, 0xee, 0xfd, 0xdd, 0xdf, 0xbb, 0xbb,
    0x80,

    /* U+0033 "3" */
    0xe, 0xee, 0x1, 0xdd, 0xc0, 0x3b, 0xb8, 0x0,
    0x0, 0xe, 0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0,
    0x38, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x0, 0x1c,
    0x0, 0x3, 0x80, 0x0, 0x0, 0xee, 0xe0, 0x1d,
    0xdc, 0x3, 0xbb, 0x80, 0x0, 0x0, 0x0, 0x0,
    0xe0, 0x0, 0x1c, 0x0, 0x3, 0x80, 0x0, 0xe,
    0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0, 0x38, 0x0,
    0x0, 0xe, 0xee, 0x1, 0xdd, 0xc0, 0x3b, 0xb8,
    0x0,

    /* U+0034 "4" */
    0x0, 0xe, 0x0, 0x1, 0xc0, 0x0, 0x38, 0x0,
    0x0, 0x0, 0xe, 0xe0, 0x1, 0xdc, 0x0, 0x3b,
    0x80, 0x0, 0x0, 0xe, 0xe, 0x1, 0xc1, 0xc0,
    0x38, 0x38, 0x0, 0x0, 0xe, 0x0, 0xe1, 0xc0,
    0x1c, 0x38, 0x3, 0x80, 0x0, 0x0, 0xee, 0xee,
    0xfd, 0xdd, 0xdf, 0xbb, 0xbb, 0x80, 0x0, 0x0,
    0x0, 0xe0, 0x0, 0x1c, 0x0, 0x3, 0x80, 0x0,
    0x0, 0x0, 0xe, 0x0, 0x1, 0xc0, 0x0, 0x38,
    0x0,

    /* U+0035 "5" */
    0xee, 0xee, 0xfd, 0xdd, 0xdf, 0xbb, 0xbb, 0x80,
    0x0, 0xe, 0x0, 0x1, 0xc0, 0x0, 0x38, 0x0,
    0x0, 0x0, 0x0, 0xee, 0xee, 0x1d, 0xdd, 0xc3,
    0xbb, 0xb8, 0x0, 0x0, 0x0, 0x0, 0xe, 0x0,
    0x1, 0xc0, 0x0, 0x38, 0x0, 0x0, 0x0, 0x0,
    0xe0, 0x0, 0x1c, 0x0, 0x3, 0x80, 0x0, 0xe,
    0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0, 0x38, 0x0,
    0x0, 0xe, 0xee, 0x1, 0xdd, 0xc0, 0x3b, 0xb8,
    0x0,

    /* U+0036 "6" */
    0x0, 0xee, 0x0, 0x1d, 0xc0, 0x3, 0xb8, 0x0,
    0x0, 0x0, 0xe0, 0x0, 0x1c, 0x0, 0x3, 0x80,
    0x0, 0x0, 0x0, 0xe0, 0x0, 0x1c, 0x0, 0x3,
    0x80, 0x0, 0x0, 0x0, 0xe, 0xee, 0xe1, 0xdd,
    0xdc, 0x3b, 0xbb, 0x80, 0x0, 0x0, 0xe0, 0x0,
    0xfc, 0x0, 0x1f, 0x80, 0x3, 0x80, 0x0, 0xe,
    0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0, 0x38, 0x0,
    0x0, 0xe, 0xee, 0x1, 0xdd, 0xc0, 0x3b, 0xb8,
    0x0,

    /* U+0037 "7" */
    0xee, 0xee, 0xfd, 0xdd, 0xdf, 0xbb, 0xbb, 0x80,
    0x0, 0x0, 0x0, 0xe, 0x0, 0x1, 0xc0, 0x0,
    0x38, 0x0, 0x0, 0x0, 0xe, 0x0, 0x1, 0xc0,
    0x0, 0x38, 0x0, 0x0, 0x0, 0xe, 0x0, 0x1,
    0xc0, 0x0, 0x38, 0x0, 0x0, 0x0, 0xe, 0x0,
    0x1, 0xc0, 0x0, 0x38, 0x0, 0x0, 0x0, 0xe,
    0x0, 0x1, 0xc0, 0x0, 0x38, 0x0, 0x0, 0x0,
    0x0, 0xe0, 0x0, 0x1c, 0x0, 0x3, 0x80, 0x0,
    0x0,

    /* U+0038 "8" */
    0xe, 0xee, 0x1, 0xdd, 0xc0, 0x3b, 0xb8, 0x0,
    0x0, 0xe, 0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0,
    0x38, 0x0, 0x0, 0xe0, 0x0, 0xfc, 0x0, 0x1f,
    0x80, 0x3, 0x80, 0x0, 0x0, 0xee, 0xe0, 0x1d,
    0xdc, 0x3, 0xbb, 0x80, 0x0, 0x0, 0xe0, 0x0,
    0xfc, 0x0, 0x1f, 0x80, 0x3, 0x80, 0x0, 0xe,
    0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0, 0x38, 0x0,
    0x0, 0xe, 0xee, 0x1, 0xdd, 0xc0, 0x3b, 0xb8,
    0x0,

    /* U+0039 "9" */
    0xe, 0xee, 0x1, 0xdd, 0xc0, 0x3b, 0xb8, 0x0,
    0x0, 0xe, 0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0,
    0x38, 0x0, 0x0, 0xe0, 0x0, 0xfc, 0x0, 0x1f,
    0x80, 0x3, 0x80, 0x0, 0x0, 0xee, 0xee, 0x1d,
    0xdd, 0xc3, 0xbb, 0xb8, 0x0, 0x0, 0x0, 0x0,
    0xe0, 0x0, 0x1c, 0x0, 0x3, 0x80, 0x0, 0x0,
    0x0, 0xe0, 0x0, 0x1c, 0x0, 0x3, 0x80, 0x0,
    0x0, 0xe, 0xe0, 0x1, 0xdc, 0x0, 0x3b, 0x80,
    0x0,

    /* U+0041 "A" */
    0xe, 0xee, 0x1, 0xdd, 0xc0, 0x3b, 0xb8, 0x0,
    0x0, 0xe, 0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0,
    0x38, 0x0, 0x0, 0xe0, 0x0, 0xfc, 0x0, 0x1f,
    0x80, 0x3, 0x80, 0x0, 0xe, 0xee, 0xef, 0xdd,
    0xdd, 0xfb, 0xbb, 0xb8, 0x0, 0x0, 0xe0, 0x0,
    0xfc, 0x0, 0x1f, 0x80, 0x3, 0x80, 0x0, 0xe,
    0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0, 0x38, 0x0,
    0x0, 0xe0, 0x0, 0xfc, 0x0, 0x1f, 0x80, 0x3,
    0x80,

    /* U+0044 "D" */
    0xee, 0xee, 0x1d, 0xdd, 0xc3, 0xbb, 0xb8, 0x0,
    0x0, 0xe, 0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0,
    0x38, 0x0, 0x0, 0xe0, 0x0, 0xfc, 0x0, 0x1f,
    0x80, 0x3, 0x80, 0x0, 0xe, 0x0, 0xf, 0xc0,
    0x1, 0xf8, 0x0, 0x38, 0x0, 0x0, 0xe0, 0x0,
    0xfc, 0x0, 0x1f, 0x80, 0x3, 0x80, 0x0, 0xe,
    0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0, 0x38, 0x0,
    0x0, 0xee, 0xee, 0x1d, 0xdd, 0xc3, 0xbb, 0xb8,
    0x0,

    /* U+0045 "E" */
    0xee, 0xee, 0xfd, 0xdd, 0xdf, 0xbb, 0xbb, 0x80,
    0x0, 0xe, 0x0, 0x1, 0xc0, 0x0, 0x38, 0x0,
    0x0, 0x0, 0x0, 0xe0, 0x0, 0x1c, 0x0, 0x3,
    0x80, 0x0, 0x0, 0x0, 0xe, 0xee, 0xef, 0xdd,
    0xdd, 0xfb, 0xbb, 0xb8, 0x0, 0x0, 0xe0, 0x0,
    0x1c, 0x0, 0x3, 0x80, 0x0, 0x0, 0x0, 0xe,
    0x0, 0x1, 0xc0, 0x0, 0x38, 0x0, 0x0, 0x0,
    0x0, 0xee, 0xee, 0xfd, 0xdd, 0xdf, 0xbb, 0xbb,
    0x80,

    /* U+0046 "F" */
    0xee, 0xee, 0xfd, 0xdd, 0xdf, 0xbb, 0xbb, 0x80,
    0x0, 0xe, 0x0, 0x1, 0xc0, 0x0, 0x38, 0x0,
    0x0, 0x0, 0x0, 0xe0, 0x0, 0x1c, 0x0, 0x3,
    0x80, 0x0, 0x0, 0x0, 0xe, 0xee, 0xef, 0xdd,
    0xdd, 0xfb, 0xbb, 0xb8, 0x0, 0x0, 0xe0, 0x0,
    0x1c, 0x0, 0x3, 0x80, 0x0, 0x0, 0x0, 0xe,
    0x0, 0x1, 0xc0, 0x0, 0x38, 0x0, 0x0, 0x0,
    0x0, 0xe0, 0x0, 0x1c, 0x0, 0x3, 0x80, 0x0,
    0x0,

    /* U+0048 "H" */
    0xe0, 0x0, 0xfc, 0x0, 0x1f, 0x80, 0x3, 0x80,
    0x0, 0xe, 0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0,
    0x38, 0x0, 0x0, 0xe0, 0x0, 0xfc, 0x0, 0x1f,
    0x80, 0x3, 0x80, 0x0, 0xe, 0xee, 0xef, 0xdd,
    0xdd, 0xfb, 0xbb, 0xb8, 0x0, 0x0, 0xe0, 0x0,
    0xfc, 0x0, 0x1f, 0x80, 0x3, 0x80, 0x0, 0xe,
    0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0, 0x38, 0x0,
    0x0, 0xe0, 0x0, 0xfc, 0x0, 0x1f, 0x80, 0x3,
    0x80,

    /* U+0049 "I" */
    0xee, 0xfd, 0xdf, 0xbb, 0x80, 0x0, 0xe0, 0x1c,
    0x3, 0x80, 0x0, 0xe, 0x1, 0xc0, 0x38, 0x0,
    0x0, 0xe0, 0x1c, 0x3, 0x80, 0x0, 0xe, 0x1,
    0xc0, 0x38, 0x0, 0x0, 0xe0, 0x1c, 0x3, 0x80,
    0x0, 0xee, 0xfd, 0xdf, 0xbb, 0x80,

    /* U+004B "K" */
    0xe0, 0x0, 0xfc, 0x0, 0x1f, 0x80, 0x3, 0x80,
    0x0, 0xe, 0x0, 0xe1, 0xc0, 0x1c, 0x38, 0x3,
    0x80, 0x0, 0x0, 0xe0, 0xe0, 0x1c, 0x1c, 0x3,
    0x83, 0x80, 0x0, 0x0, 0xe, 0xe0, 0x1, 0xdc,
    0x0, 0x3b, 0x80, 0x0, 0x0, 0x0, 0xe0, 0xe0,
    0x1c, 0x1c, 0x3, 0x83, 0x80, 0x0, 0x0, 0xe,
    0x0, 0xe1, 0xc0, 0x1c, 0x38, 0x3, 0x80, 0x0,
    0x0, 0xe0, 0x0, 0xfc, 0x0, 0x1f, 0x80, 0x3,
    0x80,

    /* U+004D "M" */
    0xe0, 0x0, 0xfc, 0x0, 0x1f, 0x80, 0x3, 0x80,
    0x0, 0xe, 0xe0, 0xef, 0xdc, 0x1d, 0xfb, 0x83,
    0xb8, 0x0, 0x0, 0xe0, 0xe0, 0xfc, 0x1c, 0x1f,
    0x83, 0x83, 0x80, 0x0, 0xe, 0xe, 0xf, 0xc1,
    0xc1, 0xf8, 0x38, 0x38, 0x0, 0x0, 0xe0, 0x0,
    0xfc, 0x0, 0x1f, 0x80, 0x3, 0x80, 0x0, 0xe,
    0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0, 0x38, 0x0,
    0x0, 0xe0, 0x0, 0xfc, 0x0, 0x1f, 0x80, 0x3,
    0x80,

    /* U+004E "N" */
    0xe0, 0x0, 0xfc, 0x0, 0x1f, 0x80, 0x3, 0x80,
    0x0, 0xe, 0xe0, 0xf, 0xdc, 0x1, 0xfb, 0x80,
    0x38, 0x0, 0x0, 0xe0, 0xe0, 0xfc, 0x1c, 0x1f,
    0x83, 0x83, 0x80, 0x0, 0xe, 0x0, 0xef, 0xc0,
    0x1d, 0xf8, 0x3, 0xb8, 0x0, 0x0, 0xe0, 0x0,
    0xfc, 0x0, 0x1f, 0x80, 0x3, 0x80, 0x0, 0xe,
    0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0, 0x38, 0x0,
    0x0, 0xe0, 0x0, 0xfc, 0x0, 0x1f, 0x80, 0x3,
    0x80,

    /* U+004F "O" */
    0xe, 0xee, 0x1, 0xdd, 0xc0, 0x3b, 0xb8, 0x0,
    0x0, 0xe, 0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0,
    0x38, 0x0, 0x0, 0xe0, 0x0, 0xfc, 0x0, 0x1f,
    0x80, 0x3, 0x80, 0x0, 0xe, 0x0, 0xf, 0xc0,
    0x1, 0xf8, 0x0, 0x38, 0x0, 0x0, 0xe0, 0x0,
    0xfc, 0x0, 0x1f, 0x80, 0x3, 0x80, 0x0, 0xe,
    0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0, 0x38, 0x0,
    0x0, 0xe, 0xee, 0x1, 0xdd, 0xc0, 0x3b, 0xb8,
    0x0,

    /* U+0052 "R" */
    0xee, 0xee, 0x1d, 0xdd, 0xc3, 0xbb, 0xb8, 0x0,
    0x0, 0xe, 0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0,
    0x38, 0x0, 0x0, 0xe0, 0x0, 0xfc, 0x0, 0x1f,
    0x80, 0x3, 0x80, 0x0, 0xe, 0xee, 0xe1, 0xdd,
    0xdc, 0x3b, 0xbb, 0x80, 0x0, 0x0, 0xe0, 0x0,
    0xfc, 0x0, 0x1f, 0x80, 0x3, 0x80, 0x0, 0xe,
    0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0, 0x38, 0x0,
    0x0, 0xe0, 0x0, 0xfc, 0x0, 0x1f, 0x80, 0x3,
    0x80,

    /* U+0053 "S" */
    0xe, 0xee, 0x1, 0xdd, 0xc0, 0x3b, 0xb8, 0x0,
    0x0, 0xe, 0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0,
    0x38, 0x0, 0x0, 0xe0, 0x0, 0x1c, 0x0, 0x3,
    0x80, 0x0, 0x0, 0x0, 0x0, 0xee, 0xe0, 0x1d,
    0xdc, 0x3, 0xbb, 0x80, 0x0, 0x0, 0x0, 0x0,
    0xe0, 0x0, 0x1c, 0x0, 0x3, 0x80, 0x0, 0xe,
    0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0, 0x38, 0x0,
    0x0, 0xe, 0xee, 0x1, 0xdd, 0xc0, 0x3b, 0xb8,
    0x0,

    /* U+0054 "T" */
    0xee, 0xee, 0xfd, 0xdd, 0xdf, 0xbb, 0xbb, 0x80,
    0x0, 0x0, 0xe, 0x0, 0x1, 0xc0, 0x0, 0x38,
    0x0, 0x0, 0x0, 0x0, 0xe0, 0x0, 0x1c, 0x0,
    0x3, 0x80, 0x0, 0x0, 0x0, 0xe, 0x0, 0x1,
    0xc0, 0x0, 0x38, 0x0, 0x0, 0x0, 0x0, 0xe0,
    0x0, 0x1c, 0x0, 0x3, 0x80, 0x0, 0x0, 0x0,
    0xe, 0x0, 0x1, 0xc0, 0x0, 0x38, 0x0, 0x0,
    0x0, 0x0, 0xe0, 0x0, 0x1c, 0x0, 0x3, 0x80,
    0x0,

    /* U+0055 "U" */
    0xe0, 0x0, 0xfc, 0x0, 0x1f, 0x80, 0x3, 0x80,
    0x0, 0xe, 0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0,
    0x38, 0x0, 0x0, 0xe0, 0x0, 0xfc, 0x0, 0x1f,
    0x80, 0x3, 0x80, 0x0, 0xe, 0x0, 0xf, 0xc0,
    0x1, 0xf8, 0x0, 0x38, 0x0, 0x0, 0xe0, 0x0,
    0xfc, 0x0, 0x1f, 0x80, 0x3, 0x80, 0x0, 0xe,
    0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0, 0x38, 0x0,
    0x0, 0xe, 0xee, 0x1, 0xdd, 0xc0, 0x3b, 0xb8,
    0x0,

    /* U+0057 "W" */
    0xe0, 0x0, 0xfc, 0x0, 0x1f, 0x80, 0x3, 0x80,
    0x0, 0xe, 0x0, 0xf, 0xc0, 0x1, 0xf8, 0x0,
    0x38, 0x0, 0x0, 0xe0, 0x0, 0xfc, 0x0, 0x1f,
    0x80, 0x3, 0x80, 0x0, 0xe, 0xe, 0xf, 0xc1,
    0xc1, 0xf8, 0x38, 0x38, 0x0, 0x0, 0xe0, 0xe0,
    0xfc, 0x1c, 0x1f, 0x83, 0x83, 0x80, 0x0, 0xe,
    0xe0, 0xef, 0xdc, 0x1d, 0xfb, 0x83, 0xb8, 0x0,
    0x0, 0xe0, 0x0, 0xfc, 0x0, 0x1f, 0x80, 0x3,
    0x80
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 353, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 353, .box_w = 11, .box_h = 3, .ofs_x = 5, .ofs_y = 8},
    {.bitmap_index = 6, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 71, .adv_w = 353, .box_w = 11, .box_h = 27, .ofs_x = 5, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 239, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 304, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 369, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 434, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 499, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 564, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 629, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 694, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 759, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 824, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 889, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 954, .adv_w = 353, .box_w = 11, .box_h = 27, .ofs_x = 5, .ofs_y = 0},
    {.bitmap_index = 992, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1057, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1122, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1187, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1252, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1317, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1382, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1447, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1512, .adv_w = 353, .box_w = 19, .box_h = 27, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0xd, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
    0x16, 0x17, 0x18, 0x19, 0x21, 0x24, 0x25, 0x26,
    0x28, 0x29, 0x2b, 0x2d, 0x2e, 0x2f, 0x32, 0x33,
    0x34, 0x35, 0x37
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 56, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 27, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t lv_font_dots_40 = {
#else
lv_font_t lv_font_dots_40 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 27,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -5,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if LV_FONT_DOTS_40*/

