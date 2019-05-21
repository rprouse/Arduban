#ifndef IMAGES_H
#define IMAGES_H

const unsigned char PROGMEM Intro[] =
{
    // width, height,
    128, 64,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xf0, 0xf8, 0xfc, 0xfc, 0x00, 0xf0, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0x3c, 0x38, 0x30, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x30, 0x38, 0x3c, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf0, 0x00, 0x00, 0xe0, 0xf0, 0xf8, 0xf8, 0xfc, 0x3c, 0x3c, 0x3c, 0xfc, 0xfc, 0xfc, 0xf8, 0xf0, 0xe0, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x30, 0x38, 0x3c, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xc0, 0xc1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x01, 0x01, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xc3, 0xe3, 0xf3, 0xf3, 0xfb, 0x38, 0x3c, 0x1c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x03, 0x03, 0x03, 0x03, 0x03, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x70, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x78, 0x38, 0x18, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x1f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x78, 0x38, 0x18, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x18, 0x38, 0x78, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x1f, 0x00, 0x00, 0x1f, 0x3f, 0x7f, 0x7f, 0x7f, 0x78, 0x38, 0x18, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x60, 0x70, 0x68, 0xc8, 0x18, 0x70, 0xd0, 0x20, 0x90, 0x60, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x32, 0x76, 0xfe, 0xf6, 0xf5, 0x20, 0x8d, 0x13, 0xb4, 0xbb, 0xfb, 0x7f, 0xfc, 0x3f, 0x34, 0x38, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x10, 0x0c, 0x43, 0x40, 0x06, 0x0e, 0x3e, 0x7e, 0xf3, 0xdb, 0xbb, 0xf3, 0xfb, 0xbb, 0xfb, 0xf9, 0xed, 0xfd, 0x7d, 0xf9, 0xf5, 0xdd, 0xb9, 0xf7, 0xce, 0xb8, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0xce, 0xb6, 0xf5, 0xf4, 0x88, 0xc0, 0xd9, 0x47, 0xf7, 0x4f, 0x1e, 0xdb, 0xd7, 0x1f, 0x5f, 0x2e, 0xa6, 0xe3, 0x40, 0xf0, 0x70, 0xd4, 0xbc, 0xfa, 0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18, 0x06, 0x41, 0x10, 0x04, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x03, 0x0f, 0x1e, 0x7d, 0xf7, 0xdf, 0xbd, 0xbf, 0xaf, 0xbf, 0xbf, 0xbb, 0xef, 0xdf, 0xfe, 0xfd, 0xf7, 0xfe, 0xf9, 0xf7, 0xce, 0xf8, 0xf0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x02, 0x01, 0x00, 0x18, 0x95, 0xdb, 0xcb, 0x5c, 0x9f, 0x00, 0x5b, 0x5f, 0x8b, 0x60, 0x11, 0x0c, 0x01, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x1e, 0x61, 0xc0, 0x0e, 0x31, 0x60, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x40, 0x10, 0x06, 0x00, 0xc0, 0xf0, 0x7a, 0xdb, 0xef, 0xed, 0xed, 0xed, 0xfd, 0xfd, 0x7d, 0xfd, 0xfd, 0x7d, 0xdd, 0xfd, 0x7d, 0x9d, 0xef, 0x77, 0x1f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};


const unsigned char PROGMEM Box[] =
{
    8, 8,
    0xfc, 0x8a, 0x8a, 0x9a, 0x9a, 0x8a, 0x8a, 0xfc,
};

const unsigned char PROGMEM BoxOnGoal[] =
{
    // width, height,
    8, 8,
    // FRAME 00
    0xfc, 0xfa, 0xfa, 0xda, 0xda, 0xfa, 0xfa, 0xfc,
    // FRAME 01
    0xfc, 0xfa, 0xda, 0x8a, 0x8a, 0xda, 0xfa, 0xfc,
};

const unsigned char PROGMEM Goal[] =
{
    // width, height,
    8, 8,
    // FRAME 00
    0x00, 0x00, 0x18, 0x24, 0x24, 0x18, 0x00, 0x00,
    // FRAME 01
    0x00, 0x18, 0x24, 0x42, 0x42, 0x24, 0x18, 0x00,
    // FRAME 02
    0x00, 0x00, 0x18, 0x24, 0x24, 0x18, 0x00, 0x00,
    // FRAME 03
    0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00,
};

const unsigned char PROGMEM Player[] =
{
    // width, height,
    8, 8,
    // FRAME 00
    0x00, 0x30, 0x88, 0xfe, 0x3e, 0xe8, 0x86, 0x00,
    // FRAME 01
    0x00, 0x10, 0x88, 0xfe, 0x3e, 0xe8, 0x84, 0x00,
    // FRAME 02
    0x00, 0x86, 0xe8, 0x3e, 0xfe, 0x88, 0x30, 0x00,
    // FRAME 03
    0x00, 0x84, 0xe8, 0x3e, 0xfe, 0x88, 0x10, 0x00,
};

const unsigned char PROGMEM Explode[] =
{
    // width, height,
    8, 8,
    // FRAME 00
    0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
    // FRAME 01
    0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00,
    // FRAME 02
    0x00, 0x00, 0x08, 0x1c, 0x1c, 0x08, 0x00, 0x00,
    // FRAME 03
    0x00, 0x00, 0x1c, 0x3e, 0x3e, 0x1c, 0x00, 0x00,
    // FRAME 04
    0x00, 0x22, 0x1c, 0x3a, 0x2e, 0x1c, 0x22, 0x00,
    // FRAME 05
    0x14, 0x2a, 0xca, 0x35, 0x48, 0x95, 0xa2, 0x54,
};

const unsigned char PROGMEM Wall[] =
{
    8, 8,
    0x00, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x00,
};

#endif