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

#ifndef LV_FONT_7SEGMENT_40
#define LV_FONT_7SEGMENT_40 1
#endif

#if LV_FONT_7SEGMENT_40

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+002D "-" */
    0x3f, 0xc7, 0xff, 0x7f, 0xf3, 0xfc,

    /* U+0030 "0" */
    0x1f, 0xfc, 0x1f, 0xfb, 0x6f, 0xff, 0x77, 0xf7,
    0x78, 0xf, 0x78, 0xf, 0x78, 0xf, 0x78, 0xf,
    0x78, 0xf, 0x78, 0xf, 0x78, 0xf, 0x78, 0xf,
    0x78, 0xf, 0x70, 0x7, 0x0, 0x0, 0x0, 0x0,
    0xe0, 0x7, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf,
    0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf,
    0xf0, 0xf, 0xf0, 0xf, 0xef, 0xef, 0xdf, 0xef,
    0xbf, 0xfe, 0x3f, 0xf8,

    /* U+0031 "1" */
    0x11, 0xce, 0xf7, 0xbd, 0xef, 0x7b, 0xde, 0xf7,
    0x9c, 0x0, 0x77, 0xbd, 0xef, 0x7b, 0xde, 0xf7,
    0xbc, 0xe6, 0x20,

    /* U+0032 "2" */
    0x1f, 0xf8, 0x1f, 0xfa, 0xf, 0xf7, 0x7, 0xf7,
    0x0, 0xf, 0x0, 0xf, 0x0, 0xf, 0x0, 0xf,
    0x0, 0xf, 0x0, 0xf, 0x0, 0xf, 0x0, 0xf,
    0x0, 0xf, 0xf, 0xf7, 0x1f, 0xf8, 0x1f, 0xf8,
    0xef, 0xf0, 0xf0, 0x0, 0xf0, 0x0, 0xf0, 0x0,
    0xf0, 0x0, 0xf0, 0x0, 0xf0, 0x0, 0xf0, 0x0,
    0xf0, 0x0, 0xf0, 0x0, 0xef, 0xe0, 0xdf, 0xe0,
    0x3f, 0xe0, 0x7f, 0xe0,

    /* U+0033 "3" */
    0x1f, 0xf8, 0x3f, 0xfe, 0x1f, 0xf7, 0xf, 0xf7,
    0x0, 0xf, 0x0, 0xf, 0x0, 0xf, 0x0, 0xf,
    0x0, 0xf, 0x0, 0xf, 0x0, 0xf, 0x0, 0xf,
    0x0, 0xf, 0x1f, 0xf7, 0x3f, 0xf8, 0x3f, 0xf8,
    0x1f, 0xe6, 0x0, 0x1e, 0x0, 0x1e, 0x0, 0x1e,
    0x0, 0x1e, 0x0, 0x1e, 0x0, 0x1e, 0x0, 0x1e,
    0x0, 0x1e, 0x0, 0x1e, 0x1f, 0xde, 0x3f, 0xee,
    0x7f, 0xec, 0x7f, 0xe8,

    /* U+0034 "4" */
    0x0, 0x2, 0x40, 0x7, 0xe0, 0x7, 0xe0, 0xf,
    0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf,
    0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf,
    0xf0, 0xf, 0xcf, 0xf7, 0x3f, 0xf8, 0x3f, 0xf8,
    0x1f, 0xe6, 0x0, 0x1e, 0x0, 0x1e, 0x0, 0x1e,
    0x0, 0x1e, 0x0, 0x1e, 0x0, 0x1e, 0x0, 0x1e,
    0x0, 0x1e, 0x0, 0x1e, 0x0, 0x1e, 0x0, 0x1e,
    0x0, 0xc, 0x0, 0x8,

    /* U+0035 "5" */
    0x1f, 0xf8, 0x7f, 0xf3, 0x7f, 0xc7, 0x7f, 0x8f,
    0x0, 0x1e, 0x0, 0x3c, 0x0, 0x78, 0x0, 0xf0,
    0x1, 0xe0, 0x3, 0xc0, 0x7, 0x80, 0xf, 0x0,
    0x19, 0xfe, 0xf, 0xfe, 0x1f, 0xfc, 0x1f, 0xe6,
    0x0, 0x3c, 0x0, 0x78, 0x0, 0xf0, 0x1, 0xe0,
    0x3, 0xc0, 0x7, 0x80, 0xf, 0x0, 0x1e, 0x0,
    0x3c, 0x7f, 0x79, 0xff, 0x77, 0xfe, 0xcf, 0xfd,
    0x0,

    /* U+0036 "6" */
    0x1f, 0xfc, 0x1f, 0xfc, 0x6f, 0xf8, 0x77, 0xf8,
    0x78, 0x0, 0x78, 0x0, 0x78, 0x0, 0x78, 0x0,
    0x78, 0x0, 0x78, 0x0, 0x78, 0x0, 0x78, 0x0,
    0x78, 0x0, 0x67, 0xf8, 0x1f, 0xfc, 0x1f, 0xfc,
    0xef, 0xf3, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf,
    0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf,
    0xf0, 0xf, 0xf0, 0xf, 0xef, 0xef, 0xdf, 0xf7,
    0xbf, 0xf6, 0x3f, 0xf4,

    /* U+0037 "7" */
    0x7f, 0xe3, 0xff, 0xa7, 0xfd, 0xcf, 0xf7, 0x0,
    0x3c, 0x0, 0xf0, 0x3, 0xc0, 0xf, 0x0, 0x3c,
    0x0, 0xf0, 0x3, 0xc0, 0xf, 0x0, 0x3c, 0x0,
    0x70, 0x0, 0x80, 0x0, 0x0, 0x18, 0x0, 0xe0,
    0x7, 0x80, 0x1e, 0x0, 0x78, 0x1, 0xe0, 0x7,
    0x80, 0x1e, 0x0, 0x78, 0x1, 0xe0, 0x7, 0x80,
    0x1e, 0x0, 0x38, 0x0, 0xc0,

    /* U+0038 "8" */
    0x1f, 0xfc, 0x1f, 0xfb, 0x6f, 0xff, 0x77, 0xf7,
    0x78, 0xf, 0x78, 0xf, 0x78, 0xf, 0x78, 0xf,
    0x78, 0xf, 0x78, 0xf, 0x78, 0xf, 0x78, 0xf,
    0x78, 0xf, 0x67, 0xff, 0x1f, 0xfc, 0x1f, 0xfc,
    0xef, 0xf7, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf,
    0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf,
    0xf0, 0xf, 0xf0, 0xf, 0xef, 0xef, 0xdf, 0xef,
    0xbf, 0xfe, 0x3f, 0xf8,

    /* U+0039 "9" */
    0x1f, 0xf8, 0x3f, 0xfe, 0xdf, 0xf7, 0xef, 0xf7,
    0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf,
    0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf, 0xf0, 0xf,
    0xf0, 0xf, 0xcf, 0xf7, 0x3f, 0xf8, 0x3f, 0xf8,
    0x1f, 0xe6, 0x0, 0x1e, 0x0, 0x1e, 0x0, 0x1e,
    0x0, 0x1e, 0x0, 0x1e, 0x0, 0x1e, 0x0, 0x1e,
    0x0, 0x1e, 0x0, 0x1e, 0x1f, 0xde, 0x3f, 0xee,
    0x7f, 0xec, 0x7f, 0xe8,

    /* U+003A ":" */
    0x7b, 0xde, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x7b, 0xde, 0xf0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 300, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 300, .box_w = 12, .box_h = 4, .ofs_x = 4, .ofs_y = 13},
    {.bitmap_index = 7, .adv_w = 300, .box_w = 16, .box_h = 30, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 67, .adv_w = 300, .box_w = 5, .box_h = 30, .ofs_x = 14, .ofs_y = 0},
    {.bitmap_index = 86, .adv_w = 300, .box_w = 16, .box_h = 30, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 146, .adv_w = 300, .box_w = 16, .box_h = 30, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 206, .adv_w = 300, .box_w = 16, .box_h = 30, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 266, .adv_w = 300, .box_w = 15, .box_h = 30, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 323, .adv_w = 300, .box_w = 16, .box_h = 30, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 383, .adv_w = 300, .box_w = 14, .box_h = 30, .ofs_x = 5, .ofs_y = 0},
    {.bitmap_index = 436, .adv_w = 300, .box_w = 16, .box_h = 30, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 496, .adv_w = 300, .box_w = 16, .box_h = 30, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 556, .adv_w = 113, .box_w = 5, .box_h = 17, .ofs_x = 2, .ofs_y = 7}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0xd
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 14, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 2, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    },
    {
        .range_start = 48, .range_length = 11, .glyph_id_start = 3,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
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
    .cmap_num = 2,
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
const lv_font_t lv_font_7segment_40 = {
#else
lv_font_t lv_font_7segment_40 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 30,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if LV_FONT_7SEGMENT_40*/
