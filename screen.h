#ifndef SCREEN_H
#define SCREEN_H

#include "ssd1306.h"

#include <stdint.h>

const unsigned char joystick_select [] = {
	0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 
	0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 
	0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 
	0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 
	0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 
	0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0x05, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xf5, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xf4, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xf6, 0xff, 0xdd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf6, 0xe7, 0xb5, 0xcf, 0x6f, 0xfb, 0xff, 0x7f, 
	0xf6, 0xc3, 0xdd, 0xd3, 0xdf, 0xdf, 0xff, 0x7f, 0xf6, 0xdb, 0x7d, 0xdc, 0x7f, 0xec, 0xff, 0x7f, 
	0xf6, 0x9d, 0xbd, 0xdf, 0xbf, 0xfb, 0xff, 0x7f, 0xf6, 0x9d, 0xbd, 0x9f, 0xdf, 0xf7, 0xff, 0x7f, 
	0x96, 0x95, 0xcd, 0x9f, 0xdf, 0x8e, 0xff, 0x7f, 0x16, 0xb0, 0xcd, 0x9f, 0xdf, 0x8e, 0xff, 0x7f, 
	0x96, 0x95, 0xbd, 0x9f, 0xdf, 0xf7, 0xff, 0x7f, 0xf6, 0x9d, 0x3d, 0xdf, 0xbf, 0xfb, 0xff, 0x7f, 
	0xf6, 0x9d, 0xed, 0xd8, 0x7f, 0xfc, 0xff, 0x7f, 0xf6, 0xc9, 0xdd, 0xd7, 0xdf, 0xef, 0xff, 0x7f, 
	0xf6, 0xc3, 0xb5, 0xcf, 0x6f, 0xdb, 0xff, 0x7f, 0xf6, 0xff, 0xed, 0xff, 0x7f, 0xfb, 0xff, 0x7f, 
	0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf6, 0xef, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xf6, 0xdf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf6, 0xdf, 0x1d, 0xe0, 0x1f, 0xe0, 0xff, 0x7f, 
	0x36, 0xe0, 0xdd, 0xee, 0xff, 0xef, 0xff, 0x7f, 0xf6, 0xff, 0xdd, 0xee, 0xff, 0xef, 0xff, 0x7f, 
	0xf6, 0xff, 0xdd, 0xee, 0xff, 0xef, 0xff, 0x7f, 0x76, 0xe0, 0x3d, 0xf1, 0xff, 0xff, 0xff, 0x7f, 
	0x76, 0xcf, 0xfd, 0xff, 0x1f, 0xe0, 0xff, 0x7f, 0xb6, 0xdf, 0xfd, 0xff, 0xdf, 0xee, 0xff, 0x7f, 
	0xb6, 0xdf, 0x1d, 0xf0, 0xdf, 0xee, 0xff, 0x7f, 0xb6, 0xdf, 0xfd, 0xe7, 0xdf, 0xee, 0xff, 0x7f, 
	0x36, 0xef, 0xfd, 0xef, 0xdf, 0xef, 0xff, 0x7f, 0x76, 0xe0, 0xfd, 0xef, 0xff, 0xff, 0xff, 0x7f, 
	0xf6, 0xff, 0xfd, 0xe7, 0x1f, 0xe0, 0xff, 0x7f, 0xb6, 0xff, 0x1d, 0xf0, 0xdf, 0xef, 0xff, 0x7f, 
	0x76, 0xfe, 0xfd, 0xff, 0xdf, 0xef, 0xff, 0x7f, 0xf6, 0xc1, 0xfd, 0xef, 0xdf, 0xef, 0xff, 0x7f, 
	0xf6, 0xc1, 0xdd, 0xe3, 0x9f, 0xe7, 0xff, 0x7f, 0x76, 0xfe, 0xdd, 0xe9, 0x3f, 0xf0, 0xff, 0x7f, 
	0xb6, 0xff, 0xdd, 0xee, 0xff, 0xff, 0xff, 0x7f, 0xf6, 0xff, 0x1d, 0xef, 0xff, 0xff, 0xff, 0x7f, 
	0x36, 0xdc, 0xdd, 0xef, 0xff, 0xff, 0xff, 0x7f, 0xb6, 0xdd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xb6, 0xdb, 0xdd, 0xe3, 0xff, 0xff, 0xff, 0x7f, 0xb6, 0xc3, 0xdd, 0xe9, 0x1f, 0xe0, 0xff, 0x7f, 
	0xf6, 0xff, 0xdd, 0xee, 0xdf, 0xfd, 0xff, 0x7f, 0xb6, 0xff, 0x1d, 0xef, 0xdf, 0xfd, 0xff, 0x7f, 
	0xb6, 0xff, 0xdd, 0xef, 0xdf, 0xf9, 0xff, 0x7f, 0x36, 0xc0, 0xfd, 0xff, 0x3f, 0xe6, 0xff, 0x7f, 
	0xb6, 0xff, 0x1d, 0xe0, 0xff, 0xff, 0xff, 0x7f, 0xb6, 0xff, 0xdd, 0xee, 0xff, 0xff, 0xff, 0x7f, 
	0xb6, 0xff, 0xdd, 0xee, 0x3f, 0xf0, 0xff, 0x7f, 0xf6, 0xff, 0xdd, 0xee, 0xbf, 0xe7, 0xff, 0x7f, 
	0xf6, 0xff, 0xdd, 0xef, 0xdf, 0xef, 0xff, 0x7f, 0x36, 0xc0, 0xfd, 0xff, 0xdf, 0xed, 0xff, 0x7f, 
	0xf6, 0xff, 0x1d, 0xe0, 0xdf, 0xed, 0xff, 0x7f, 0xf6, 0xff, 0xdd, 0xfd, 0xbf, 0xe1, 0xff, 0x7f, 
	0x76, 0xe0, 0xdd, 0xfd, 0xff, 0xff, 0xff, 0x7f, 0x36, 0xcf, 0xdd, 0xf9, 0xff, 0xff, 0xff, 0x7f, 
	0xb6, 0xdf, 0x3d, 0xe6, 0x1f, 0xe0, 0xff, 0x7f, 0xb6, 0xdf, 0xfd, 0xff, 0xdf, 0xee, 0xff, 0x7f, 
	0xb6, 0xdf, 0xfd, 0xff, 0xdf, 0xee, 0xff, 0x7f, 0xf6, 0xef, 0xfd, 0xff, 0xdf, 0xee, 0xff, 0x7f, 
	0xf6, 0xff, 0xfd, 0xff, 0x3f, 0xf1, 0xff, 0x7f, 0x36, 0xc0, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xf6, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf6, 0xf8, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0x76, 0xe7, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xb6, 0xcf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x36, 0xc0, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xf6, 0xdf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf6, 0xdf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xf6, 0xdf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0x36, 0xc0, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xb6, 0xdd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xb6, 0xdd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xb6, 0xdd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xb6, 0xdf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0x36, 0xc0, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xb6, 0xdf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xb6, 0xdf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xb6, 0xdf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0x36, 0xcf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x76, 0xe0, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf6, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0x06, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 
	0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 
	0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 
	0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 
	0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 
	0x3f, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfc, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff
};

// 'sinal_atenção', 64x128px
const unsigned char led_select [] = {
	0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 
	0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 
	0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 
	0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 
	0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 
	0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0x01, 0x00, 0xfc, 0x7f, 
	0xfe, 0xff, 0xdf, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xfe, 0xe7, 0xb7, 0xcf, 0x6d, 0xfb, 0xfd, 0x7f, 
	0xfe, 0xc3, 0xdf, 0xd3, 0xdd, 0xdf, 0xfd, 0x7f, 0xfe, 0xdb, 0x7f, 0xdc, 0x7d, 0xec, 0xfd, 0x7f, 
	0xfe, 0x9d, 0xbf, 0xdf, 0xbd, 0xfb, 0xfd, 0x7f, 0xfe, 0x9d, 0xbf, 0x9f, 0xdd, 0xf7, 0xfd, 0x7f, 
	0x9e, 0x95, 0xcf, 0x9f, 0xdd, 0x8e, 0xfd, 0x7f, 0x1e, 0xb0, 0xcf, 0x9f, 0xdd, 0x8e, 0xfd, 0x7f, 
	0x9e, 0x95, 0xbf, 0x9f, 0xdd, 0xf7, 0xfd, 0x7f, 0xfe, 0x9d, 0x3f, 0xdf, 0xbd, 0xfb, 0xfd, 0x7f, 
	0xfe, 0x9d, 0xef, 0xd8, 0x7d, 0xfc, 0xfd, 0x7f, 0xfe, 0xc9, 0xdf, 0xd7, 0xdd, 0xef, 0xfd, 0x7f, 
	0xfe, 0xc3, 0xb7, 0xcf, 0x6d, 0xdb, 0xfd, 0x7f, 0xfe, 0xff, 0xef, 0xff, 0x7d, 0xfb, 0xfd, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xfe, 0xef, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0xfe, 0xdf, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xfe, 0xdf, 0x1f, 0xe0, 0x1d, 0xe0, 0xfd, 0x7f, 
	0x3e, 0xe0, 0xdf, 0xee, 0xfd, 0xef, 0xfd, 0x7f, 0xfe, 0xff, 0xdf, 0xee, 0xfd, 0xef, 0xfd, 0x7f, 
	0xfe, 0xff, 0xdf, 0xee, 0xfd, 0xef, 0xfd, 0x7f, 0x7e, 0xe0, 0x3f, 0xf1, 0xfd, 0xff, 0xfd, 0x7f, 
	0x7e, 0xcf, 0xff, 0xff, 0x1d, 0xe0, 0xfd, 0x7f, 0xbe, 0xdf, 0xff, 0xff, 0xdd, 0xee, 0xfd, 0x7f, 
	0xbe, 0xdf, 0x1f, 0xf0, 0xdd, 0xee, 0xfd, 0x7f, 0xbe, 0xdf, 0xff, 0xe7, 0xdd, 0xee, 0xfd, 0x7f, 
	0x3e, 0xef, 0xff, 0xef, 0xdd, 0xef, 0xfd, 0x7f, 0x7e, 0xe0, 0xff, 0xef, 0xfd, 0xff, 0xfd, 0x7f, 
	0xfe, 0xff, 0xff, 0xe7, 0x1d, 0xe0, 0xfd, 0x7f, 0xbe, 0xff, 0x1f, 0xf0, 0xdd, 0xef, 0xfd, 0x7f, 
	0x7e, 0xfe, 0xff, 0xff, 0xdd, 0xef, 0xfd, 0x7f, 0xfe, 0xc1, 0xff, 0xef, 0xdd, 0xef, 0xfd, 0x7f, 
	0xfe, 0xc1, 0xdf, 0xe3, 0x9d, 0xe7, 0xfd, 0x7f, 0x7e, 0xfe, 0xdf, 0xe9, 0x3d, 0xf0, 0xfd, 0x7f, 
	0xbe, 0xff, 0xdf, 0xee, 0xfd, 0xff, 0xfd, 0x7f, 0xfe, 0xff, 0x1f, 0xef, 0xfd, 0xff, 0xfd, 0x7f, 
	0x3e, 0xdc, 0xdf, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xbe, 0xdd, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0xbe, 0xdb, 0xdf, 0xe3, 0xfd, 0xff, 0xfd, 0x7f, 0xbe, 0xc3, 0xdf, 0xe9, 0x1d, 0xe0, 0xfd, 0x7f, 
	0xfe, 0xff, 0xdf, 0xee, 0xdd, 0xfd, 0xfd, 0x7f, 0xbe, 0xff, 0x1f, 0xef, 0xdd, 0xfd, 0xfd, 0x7f, 
	0xbe, 0xff, 0xdf, 0xef, 0xdd, 0xf9, 0xfd, 0x7f, 0x3e, 0xc0, 0xff, 0xff, 0x3d, 0xe6, 0xfd, 0x7f, 
	0xbe, 0xff, 0x1f, 0xe0, 0xfd, 0xff, 0xfd, 0x7f, 0xbe, 0xff, 0xdf, 0xee, 0xfd, 0xff, 0xfd, 0x7f, 
	0xbe, 0xff, 0xdf, 0xee, 0x3d, 0xf0, 0xfd, 0x7f, 0xfe, 0xff, 0xdf, 0xee, 0xbd, 0xe7, 0xfd, 0x7f, 
	0xfe, 0xff, 0xdf, 0xef, 0xdd, 0xef, 0xfd, 0x7f, 0x3e, 0xc0, 0xff, 0xff, 0xdd, 0xed, 0xfd, 0x7f, 
	0xfe, 0xff, 0x1f, 0xe0, 0xdd, 0xed, 0xfd, 0x7f, 0xfe, 0xff, 0xdf, 0xfd, 0xbd, 0xe1, 0xfd, 0x7f, 
	0x7e, 0xe0, 0xdf, 0xfd, 0xfd, 0xff, 0xfd, 0x7f, 0x3e, 0xcf, 0xdf, 0xf9, 0xfd, 0xff, 0xfd, 0x7f, 
	0xbe, 0xdf, 0x3f, 0xe6, 0x1d, 0xe0, 0xfd, 0x7f, 0xbe, 0xdf, 0xff, 0xff, 0xdd, 0xee, 0xfd, 0x7f, 
	0xbe, 0xdf, 0xff, 0xff, 0xdd, 0xee, 0xfd, 0x7f, 0xfe, 0xef, 0xff, 0xff, 0xdd, 0xee, 0xfd, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0x3d, 0xf1, 0xfd, 0x7f, 0x3e, 0xc0, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0xfe, 0xfd, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xfe, 0xf8, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0x7e, 0xe7, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xbe, 0xcf, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0x3e, 0xc0, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0xfe, 0xdf, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xfe, 0xdf, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0xfe, 0xdf, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0x3e, 0xc0, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xbe, 0xdd, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0xbe, 0xdd, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xbe, 0xdd, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0xbe, 0xdf, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0x3e, 0xc0, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xbe, 0xdf, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0xbe, 0xdf, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xbe, 0xdf, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0x3e, 0xcf, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0x7e, 0xe0, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xfd, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0x01, 0x00, 0xfc, 0x7f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 
	0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 
	0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 
	0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 
	0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 
	0x3f, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfc, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff
};

// 'sinal_fechado', 64x128px
const unsigned char buzzer_select [] = {
	0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 
	0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 
	0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 
	0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 
	0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 
	0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xde, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xfe, 0xe7, 0xb6, 0xcf, 0x6d, 0xfb, 0xff, 0x7f, 
	0xfe, 0xc3, 0xde, 0xd3, 0xdd, 0xdf, 0xff, 0x7f, 0xfe, 0xdb, 0x7e, 0xdc, 0x7d, 0xec, 0xff, 0x7f, 
	0xfe, 0x9d, 0xbe, 0xdf, 0xbd, 0xfb, 0xff, 0x7f, 0xfe, 0x9d, 0xbe, 0x9f, 0xdd, 0xf7, 0xff, 0x7f, 
	0x9e, 0x95, 0xce, 0x9f, 0xdd, 0x8e, 0xff, 0x7f, 0x1e, 0xb0, 0xce, 0x9f, 0xdd, 0x8e, 0xff, 0x7f, 
	0x9e, 0x95, 0xbe, 0x9f, 0xdd, 0xf7, 0xff, 0x7f, 0xfe, 0x9d, 0x3e, 0xdf, 0xbd, 0xfb, 0xff, 0x7f, 
	0xfe, 0x9d, 0xee, 0xd8, 0x7d, 0xfc, 0xff, 0x7f, 0xfe, 0xc9, 0xde, 0xd7, 0xdd, 0xef, 0xff, 0x7f, 
	0xfe, 0xc3, 0xb6, 0xcf, 0x6d, 0xdb, 0xff, 0x7f, 0xfe, 0xff, 0xee, 0xff, 0x7d, 0xfb, 0xff, 0x7f, 
	0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xfe, 0xef, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0xfe, 0xdf, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xfe, 0xdf, 0x1e, 0xe0, 0x1d, 0xe0, 0xff, 0x7f, 
	0x3e, 0xe0, 0xde, 0xee, 0xfd, 0xef, 0xff, 0x7f, 0xfe, 0xff, 0xde, 0xee, 0xfd, 0xef, 0xff, 0x7f, 
	0xfe, 0xff, 0xde, 0xee, 0xfd, 0xef, 0xff, 0x7f, 0x7e, 0xe0, 0x3e, 0xf1, 0xfd, 0xff, 0xff, 0x7f, 
	0x7e, 0xcf, 0xfe, 0xff, 0x1d, 0xe0, 0xff, 0x7f, 0xbe, 0xdf, 0xfe, 0xff, 0xdd, 0xee, 0xff, 0x7f, 
	0xbe, 0xdf, 0x1e, 0xf0, 0xdd, 0xee, 0xff, 0x7f, 0xbe, 0xdf, 0xfe, 0xe7, 0xdd, 0xee, 0xff, 0x7f, 
	0x3e, 0xef, 0xfe, 0xef, 0xdd, 0xef, 0xff, 0x7f, 0x7e, 0xe0, 0xfe, 0xef, 0xfd, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xfe, 0xe7, 0x1d, 0xe0, 0xff, 0x7f, 0xbe, 0xff, 0x1e, 0xf0, 0xdd, 0xef, 0xff, 0x7f, 
	0x7e, 0xfe, 0xfe, 0xff, 0xdd, 0xef, 0xff, 0x7f, 0xfe, 0xc1, 0xfe, 0xef, 0xdd, 0xef, 0xff, 0x7f, 
	0xfe, 0xc1, 0xde, 0xe3, 0x9d, 0xe7, 0xff, 0x7f, 0x7e, 0xfe, 0xde, 0xe9, 0x3d, 0xf0, 0xff, 0x7f, 
	0xbe, 0xff, 0xde, 0xee, 0xfd, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x1e, 0xef, 0xfd, 0xff, 0xff, 0x7f, 
	0x3e, 0xdc, 0xde, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xbe, 0xdd, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0xbe, 0xdb, 0xde, 0xe3, 0xfd, 0xff, 0xff, 0x7f, 0xbe, 0xc3, 0xde, 0xe9, 0x1d, 0xe0, 0xff, 0x7f, 
	0xfe, 0xff, 0xde, 0xee, 0xdd, 0xfd, 0xff, 0x7f, 0xbe, 0xff, 0x1e, 0xef, 0xdd, 0xfd, 0xff, 0x7f, 
	0xbe, 0xff, 0xde, 0xef, 0xdd, 0xf9, 0xff, 0x7f, 0x3e, 0xc0, 0xfe, 0xff, 0x3d, 0xe6, 0xff, 0x7f, 
	0xbe, 0xff, 0x1e, 0xe0, 0xfd, 0xff, 0xff, 0x7f, 0xbe, 0xff, 0xde, 0xee, 0xfd, 0xff, 0xff, 0x7f, 
	0xbe, 0xff, 0xde, 0xee, 0x3d, 0xf0, 0xff, 0x7f, 0xfe, 0xff, 0xde, 0xee, 0xbd, 0xe7, 0xff, 0x7f, 
	0xfe, 0xff, 0xde, 0xef, 0xdd, 0xef, 0xff, 0x7f, 0x3e, 0xc0, 0xfe, 0xff, 0xdd, 0xed, 0xff, 0x7f, 
	0xfe, 0xff, 0x1e, 0xe0, 0xdd, 0xed, 0xff, 0x7f, 0xfe, 0xff, 0xde, 0xfd, 0xbd, 0xe1, 0xff, 0x7f, 
	0x7e, 0xe0, 0xde, 0xfd, 0xfd, 0xff, 0xff, 0x7f, 0x3e, 0xcf, 0xde, 0xf9, 0xfd, 0xff, 0xff, 0x7f, 
	0xbe, 0xdf, 0x3e, 0xe6, 0x1d, 0xe0, 0xff, 0x7f, 0xbe, 0xdf, 0xfe, 0xff, 0xdd, 0xee, 0xff, 0x7f, 
	0xbe, 0xdf, 0xfe, 0xff, 0xdd, 0xee, 0xff, 0x7f, 0xfe, 0xef, 0xfe, 0xff, 0xdd, 0xee, 0xff, 0x7f, 
	0xfe, 0xff, 0xfe, 0xff, 0x3d, 0xf1, 0xff, 0x7f, 0x3e, 0xc0, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0xfe, 0xfd, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xfe, 0xf8, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0x7e, 0xe7, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xbe, 0xcf, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0x3e, 0xc0, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0xfe, 0xdf, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xfe, 0xdf, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0xfe, 0xdf, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0x3e, 0xc0, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xbe, 0xdd, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0xbe, 0xdd, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xbe, 0xdd, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0xbe, 0xdf, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0x3e, 0xc0, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xbe, 0xdf, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0xbe, 0xdf, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xbe, 0xdf, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0x3e, 0xcf, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0x7e, 0xe0, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 
	0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 
	0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 
	0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 
	0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 
	0x3f, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfc, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff
};


const unsigned char exec_joy [] = {
	0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 
	0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 
	0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 
	0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 
	0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xfd, 0xff, 0xff, 0xef, 0xff, 0xff, 0xf9, 0x7f, 
	0x7d, 0x80, 0xff, 0xef, 0x0f, 0xfc, 0xe7, 0x7f, 0x7e, 0xbb, 0x1f, 0xf0, 0xf7, 0xfb, 0x9f, 0x7f, 
	0x7e, 0xbb, 0xff, 0xff, 0xf7, 0xfb, 0x7f, 0x7e, 0x7e, 0xbb, 0xff, 0xff, 0xf7, 0xfb, 0x9f, 0x7f, 
	0xfe, 0xff, 0x3f, 0xf0, 0xef, 0xfd, 0xe7, 0x7f, 0x7e, 0xbf, 0xdf, 0xef, 0xff, 0xff, 0xf9, 0x7f, 
	0xfe, 0xcc, 0xdf, 0xef, 0x07, 0xf8, 0xff, 0x7f, 0xfe, 0xf3, 0xdf, 0xef, 0xff, 0xfb, 0x03, 0x7f, 
	0xfe, 0xf3, 0xdf, 0xef, 0xff, 0xfb, 0xfd, 0x7e, 0xfe, 0xcc, 0x3f, 0xf0, 0xff, 0xfb, 0xfd, 0x7e, 
	0x7e, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x7e, 0xfe, 0xff, 0x9f, 0xff, 0x07, 0xf8, 0xfd, 0x7e, 
	0x7e, 0x80, 0x7f, 0xfe, 0xff, 0xff, 0x03, 0x7f, 0x7e, 0xbb, 0xff, 0xe1, 0xff, 0xff, 0xff, 0x7f, 
	0x7e, 0xbb, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0x7e, 0xbb, 0x9f, 0xff, 0x0f, 0xfc, 0x01, 0x7e, 
	0xfe, 0xff, 0xff, 0xff, 0xf7, 0xfb, 0xff, 0x7e, 0xfe, 0xff, 0xff, 0xff, 0xf7, 0xfb, 0xff, 0x7e, 
	0xfe, 0xc0, 0x3f, 0xf7, 0xf7, 0xfb, 0xff, 0x7e, 0x7e, 0xbf, 0xdf, 0xee, 0xef, 0xfd, 0xfd, 0x7f, 
	0x7e, 0xbf, 0xdf, 0xed, 0xff, 0xff, 0xfd, 0x7f, 0x7e, 0xbf, 0xbf, 0xf3, 0x07, 0xf8, 0x01, 0x7e, 
	0xfe, 0xde, 0xff, 0xff, 0xbf, 0xff, 0xfd, 0x7f, 0xfe, 0xff, 0xdf, 0xff, 0x5f, 0xff, 0xfd, 0x7f, 
	0x7e, 0xc0, 0xdf, 0xff, 0xef, 0xfc, 0xff, 0x7f, 0xfe, 0xbf, 0x1f, 0xe0, 0xf7, 0xfb, 0x7f, 0x7e, 
	0xfe, 0xbf, 0xdf, 0xff, 0xff, 0xff, 0x9f, 0x7f, 0xfe, 0xbf, 0xdf, 0xff, 0xff, 0xff, 0xa7, 0x7f, 
	0xfe, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xb9, 0x7f, 0x7e, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xa7, 0x7f, 
	0xfe, 0xff, 0x1f, 0xe0, 0x07, 0xf8, 0x9f, 0x7f, 0x7e, 0xff, 0xff, 0xff, 0xb7, 0xfb, 0x7f, 0x7e, 
	0x7e, 0xff, 0xff, 0xff, 0xb7, 0xfb, 0xff, 0x7f, 0x7e, 0x80, 0xff, 0xff, 0x8f, 0xfb, 0x01, 0x7e, 
	0x7e, 0xff, 0x3f, 0xf0, 0x7f, 0xfc, 0xdd, 0x7f, 0x7e, 0xff, 0xdf, 0xef, 0xff, 0xff, 0xdd, 0x7f, 
	0xfe, 0xff, 0xdf, 0xef, 0xf7, 0xff, 0x9d, 0x7f, 0xfe, 0x9f, 0xdf, 0xef, 0xf7, 0xff, 0x63, 0x7e, 
	0xfe, 0xe7, 0xbf, 0xf7, 0x07, 0xf8, 0xff, 0x7f, 0xfe, 0xe9, 0xff, 0xff, 0xf7, 0xff, 0xff, 0x7f, 
	0x7e, 0xee, 0x1f, 0xe0, 0xf7, 0xff, 0xff, 0x7f, 0xfe, 0xe9, 0xff, 0xfe, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xe7, 0x7f, 0xfd, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0x9f, 0xbf, 0xf3, 0x07, 0xf8, 0xff, 0x7f, 
	0xfe, 0xff, 0xdf, 0xef, 0xe7, 0xff, 0xff, 0x7f, 0x7e, 0x80, 0xff, 0xff, 0x9f, 0xff, 0xff, 0x7f, 
	0x7e, 0xfe, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x7f, 0xfe, 0xf9, 0xff, 0xff, 0xff, 0xf9, 0xff, 0x7f, 
	0xfe, 0xe7, 0xff, 0xff, 0x07, 0xf8, 0xff, 0x7f, 0xfe, 0x9f, 0x1f, 0xe0, 0xff, 0xff, 0xff, 0x7f, 
	0x7e, 0x80, 0xff, 0xef, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0x7f, 0x7e, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0x7e, 0xbf, 0x1f, 0xe0, 0x07, 0xf8, 0xff, 0x7f, 0x7e, 0xbf, 0xdf, 0xee, 0x77, 0xff, 0xff, 0x7f, 
	0x7e, 0xbf, 0xdf, 0xee, 0x77, 0xff, 0xff, 0x7f, 0xfe, 0xde, 0xdf, 0xee, 0x77, 0xff, 0xff, 0x7f, 
	0xfe, 0xe1, 0xff, 0xff, 0x8f, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0x7f, 
	0xfe, 0xff, 0x1f, 0xe0, 0x7f, 0xfe, 0xff, 0x7f, 0xfe, 0xc0, 0xdf, 0xef, 0x9f, 0xfe, 0xff, 0x7f, 
	0x7e, 0xbf, 0xdf, 0xef, 0xe7, 0xfe, 0xff, 0x7f, 0x7e, 0xbf, 0xdf, 0xef, 0x9f, 0xfe, 0xff, 0x7f, 
	0x7e, 0xbf, 0xbf, 0xf7, 0x7f, 0xfe, 0xff, 0x7f, 0x7e, 0xbf, 0x7f, 0xf8, 0xff, 0xf9, 0xff, 0x7f, 
	0xfe, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0x07, 0xf8, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0x77, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0x77, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xfd, 0x77, 0xfe, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xfd, 0x8f, 0xf9, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0x9f, 0xfe, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xe7, 0xfe, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0x9f, 0xfe, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 
	0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 
	0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 
	0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 
	0x7f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff
};



const unsigned char exec_led [] = {
	0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 
	0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 
	0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 
	0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 
	0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7e, 0x80, 0x1f, 0xe0, 0x07, 0xf8, 0xff, 0x7f, 
	0x7e, 0xbb, 0xdf, 0xfd, 0x77, 0xff, 0xff, 0x7f, 0x7e, 0xbb, 0xdf, 0xfd, 0x77, 0xff, 0xff, 0x7f, 
	0x7e, 0xbb, 0xdf, 0xf9, 0x77, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x3f, 0xe6, 0x8f, 0xff, 0xff, 0x7f, 
	0x7e, 0xbf, 0xff, 0xff, 0xff, 0xf9, 0xff, 0x7f, 0xfe, 0xcc, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x7f, 
	0xfe, 0xf3, 0x7f, 0xf8, 0x9f, 0xfe, 0xff, 0x7f, 0xfe, 0xf3, 0xbf, 0xf7, 0xe7, 0xfe, 0xff, 0x7f, 
	0xfe, 0xcc, 0xdf, 0xef, 0x9f, 0xfe, 0xff, 0x7f, 0x7e, 0xbf, 0xdf, 0xed, 0x7f, 0xfe, 0xff, 0x7f, 
	0xfe, 0xff, 0xdf, 0xed, 0xff, 0xf9, 0xff, 0x7f, 0x7e, 0x80, 0xbf, 0xf1, 0xff, 0xff, 0xff, 0x7f, 
	0x7e, 0xbb, 0xff, 0xff, 0x07, 0xf8, 0xff, 0x7f, 0x7e, 0xbb, 0xff, 0xff, 0x77, 0xff, 0xff, 0x7f, 
	0x7e, 0xbb, 0x1f, 0xe0, 0x77, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xdf, 0xee, 0x77, 0xfe, 0xff, 0x7f, 
	0xfe, 0xff, 0xdf, 0xee, 0x8f, 0xf9, 0xff, 0x7f, 0xfe, 0xc0, 0x3f, 0xee, 0xff, 0xff, 0xff, 0x7f, 
	0x7e, 0xbf, 0xff, 0xf1, 0xff, 0xf9, 0xff, 0x7f, 0x7e, 0xbf, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x7f, 
	0x7e, 0xbf, 0xff, 0xff, 0x9f, 0xfe, 0xff, 0x7f, 0xfe, 0xde, 0xff, 0xff, 0xe7, 0xfe, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0x9f, 0xfe, 0xff, 0x7f, 0x7e, 0xc0, 0xff, 0xfd, 0x7f, 0xfe, 0xff, 0x7f, 
	0xfe, 0xbf, 0xff, 0xfd, 0xff, 0xf9, 0xff, 0x7f, 0xfe, 0xbf, 0xff, 0xfd, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0x7e, 0xc0, 0xff, 0xff, 0xe7, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0x7f, 
	0x7e, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x7f, 0x7e, 0xff, 0x3f, 0xf0, 0xff, 0xf9, 0xff, 0x7f, 
	0x7e, 0x80, 0xdf, 0xef, 0x7f, 0xfe, 0xff, 0x7f, 0x7e, 0xff, 0xdf, 0xef, 0x9f, 0xff, 0xff, 0x7f, 
	0x7e, 0xff, 0xdf, 0xef, 0xe7, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xbf, 0xf7, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0x9f, 0xff, 0xff, 0x0f, 0xfc, 0xff, 0x7f, 0xfe, 0xe7, 0x1f, 0xe0, 0xf7, 0xfb, 0xff, 0x7f, 
	0xfe, 0xe9, 0xff, 0xef, 0xf7, 0xfb, 0xff, 0x7f, 0x7e, 0xee, 0xff, 0xef, 0xf7, 0xfb, 0xff, 0x7f, 
	0xfe, 0xe9, 0xff, 0xef, 0xf7, 0xfb, 0xff, 0x7f, 0xfe, 0xe7, 0xff, 0xff, 0x0f, 0xfc, 0xff, 0x7f, 
	0xfe, 0x9f, 0x1f, 0xe0, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0x7e, 0x80, 0xff, 0xff, 0x07, 0xf8, 0xff, 0x7f, 0x7e, 0xfe, 0xff, 0xff, 0xff, 0xfb, 0xff, 0x7f, 
	0xfe, 0xf9, 0x3f, 0xf0, 0xff, 0xfb, 0xff, 0x7f, 0xfe, 0xe7, 0xdf, 0xef, 0xff, 0xfb, 0xff, 0x7f, 
	0xfe, 0x9f, 0xdf, 0xef, 0xf7, 0xff, 0xff, 0x7f, 0x7e, 0x80, 0xdf, 0xef, 0xf7, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xbf, 0xf7, 0x07, 0xf8, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xff, 0x7f, 
	0x7e, 0x80, 0x1f, 0xe0, 0xf7, 0xff, 0xff, 0x7f, 0x7e, 0xbf, 0xff, 0xfe, 0xff, 0xff, 0xff, 0x7f, 
	0x7e, 0xbf, 0x7f, 0xfd, 0xff, 0xf9, 0xff, 0x7f, 0x7e, 0xbf, 0xbf, 0xf3, 0x7f, 0xfe, 0xff, 0x7f, 
	0xfe, 0xde, 0xdf, 0xef, 0x9f, 0xfe, 0xff, 0x7f, 0xfe, 0xe1, 0xff, 0xff, 0xe7, 0xfe, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0x9f, 0xfe, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x7f, 
	0xfe, 0xc0, 0xff, 0xff, 0xff, 0xf9, 0xff, 0x7f, 0x7e, 0xbf, 0x1f, 0xe0, 0xff, 0xff, 0xff, 0x7f, 
	0x7e, 0xbf, 0xdf, 0xee, 0x07, 0xf8, 0xff, 0x7f, 0x7e, 0xbf, 0xdf, 0xee, 0x77, 0xff, 0xff, 0x7f, 
	0x7e, 0xbf, 0x3f, 0xee, 0x77, 0xff, 0xff, 0x7f, 0xfe, 0xc0, 0xff, 0xf1, 0x77, 0xfe, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0x8f, 0xf9, 0xff, 0x7f, 0xfe, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x1f, 0xe0, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7e, 0x80, 0xdf, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xbf, 0x1f, 0xe0, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0x7e, 0x80, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0x7e, 0xbb, 0xff, 0xf9, 0xff, 0xff, 0xff, 0x7f, 
	0x7e, 0xbb, 0xff, 0xe7, 0xff, 0xff, 0xff, 0x7f, 0x7e, 0xbb, 0x1f, 0xe0, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0x7e, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7e, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0x7e, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7e, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xde, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xe1, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 
	0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 
	0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 
	0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 
	0x7f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff
};


const unsigned char exec_buzzer [] = {
	0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 
	0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 
	0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 
	0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 
	0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7e, 0x80, 0x1f, 0xe0, 0x07, 0xf8, 0xff, 0x7f, 
	0x7e, 0xbb, 0xdf, 0xee, 0xb7, 0xfb, 0xff, 0x7f, 0x7e, 0xbb, 0xdf, 0xee, 0xb7, 0xfb, 0xff, 0x7f, 
	0x7e, 0xbb, 0x3f, 0xee, 0x8f, 0xfb, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xf1, 0x7f, 0xfc, 0xff, 0x7f, 
	0x7e, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xcc, 0xff, 0xff, 0xf7, 0xff, 0xff, 0x7f, 
	0xfe, 0xf3, 0x1f, 0xf0, 0xf7, 0xff, 0xff, 0x7f, 0xfe, 0xf3, 0xff, 0xef, 0x07, 0xf8, 0xff, 0x7f, 
	0xfe, 0xcc, 0xff, 0xef, 0xf7, 0xff, 0xff, 0x7f, 0x7e, 0xbf, 0xff, 0xef, 0xf7, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0x7f, 0x7e, 0x80, 0x1f, 0xf0, 0xff, 0xff, 0xff, 0x7f, 
	0x7e, 0xbb, 0xff, 0xff, 0x07, 0xf8, 0xff, 0x7f, 0x7e, 0xbb, 0xdf, 0xe7, 0xe7, 0xff, 0xff, 0x7f, 
	0x7e, 0xbb, 0xdf, 0xeb, 0x9f, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xdf, 0xed, 0x7f, 0xfe, 0xff, 0x7f, 
	0xfe, 0xff, 0xdf, 0xee, 0xff, 0xf9, 0xff, 0x7f, 0xfe, 0xc0, 0x5f, 0xef, 0x07, 0xf8, 0xff, 0x7f, 
	0x7e, 0xbf, 0x9f, 0xef, 0xff, 0xff, 0xff, 0x7f, 0x7e, 0xbf, 0xdf, 0xe7, 0xff, 0xff, 0xff, 0x7f, 
	0x7e, 0xbf, 0xdf, 0xeb, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xde, 0xdf, 0xed, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xdf, 0xee, 0xff, 0xff, 0xff, 0x7f, 0x7e, 0xc0, 0x5f, 0xef, 0x07, 0xf8, 0xff, 0x7f, 
	0xfe, 0xbf, 0x9f, 0xef, 0x77, 0xff, 0xff, 0x7f, 0xfe, 0xbf, 0xff, 0xff, 0x77, 0xff, 0xff, 0x7f, 
	0xfe, 0xbf, 0x1f, 0xe0, 0x77, 0xff, 0xff, 0x7f, 0xfe, 0xbf, 0xdf, 0xee, 0x8f, 0xff, 0xff, 0x7f, 
	0x7e, 0xc0, 0xdf, 0xee, 0xff, 0xf9, 0xff, 0x7f, 0xfe, 0xff, 0xdf, 0xee, 0x7f, 0xfe, 0xff, 0x7f, 
	0x7e, 0xff, 0xff, 0xff, 0x9f, 0xfe, 0xff, 0x7f, 0x7e, 0xff, 0xff, 0xff, 0xe7, 0xfe, 0xff, 0x7f, 
	0x7e, 0x80, 0x1f, 0xe0, 0x9f, 0xfe, 0xff, 0x7f, 0x7e, 0xff, 0xdf, 0xfd, 0x7f, 0xfe, 0xff, 0x7f, 
	0x7e, 0xff, 0xdf, 0xfd, 0xff, 0xf9, 0xff, 0x7f, 0xfe, 0xff, 0xdf, 0xf9, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0x9f, 0x3f, 0xe6, 0x07, 0xf8, 0xff, 0x7f, 0xfe, 0xe7, 0xff, 0xff, 0x77, 0xff, 0xff, 0x7f, 
	0xfe, 0xe9, 0xff, 0xff, 0x77, 0xff, 0xff, 0x7f, 0x7e, 0xee, 0xff, 0xff, 0x77, 0xfe, 0xff, 0x7f, 
	0xfe, 0xe9, 0xff, 0xff, 0x8f, 0xf9, 0xff, 0x7f, 0xfe, 0xe7, 0xff, 0xfd, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0x9f, 0xff, 0xfd, 0xff, 0xf9, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xfd, 0x7f, 0xfe, 0xff, 0x7f, 
	0x7e, 0x80, 0xff, 0xff, 0x9f, 0xfe, 0xff, 0x7f, 0x7e, 0xfe, 0xff, 0xff, 0xe7, 0xfe, 0xff, 0x7f, 
	0xfe, 0xf9, 0xff, 0xff, 0x9f, 0xfe, 0xff, 0x7f, 0xfe, 0xe7, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x7f, 
	0xfe, 0x9f, 0xff, 0xff, 0xff, 0xf9, 0xff, 0x7f, 0x7e, 0x80, 0x3f, 0xf0, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xdf, 0xef, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xdf, 0xef, 0xff, 0xff, 0xff, 0x7f, 
	0x7e, 0x80, 0xdf, 0xef, 0xe7, 0xff, 0xff, 0x7f, 0x7e, 0xbf, 0xbf, 0xf7, 0x9f, 0xff, 0xff, 0x7f, 
	0x7e, 0xbf, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x7f, 0x7e, 0xbf, 0x1f, 0xe0, 0xff, 0xf9, 0xff, 0x7f, 
	0xfe, 0xde, 0xff, 0xef, 0x7f, 0xfe, 0xff, 0x7f, 0xfe, 0xe1, 0xff, 0xef, 0x9f, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xef, 0xe7, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xc0, 0x1f, 0xe0, 0x0f, 0xfc, 0xff, 0x7f, 0x7e, 0xbf, 0xff, 0xff, 0xf7, 0xfb, 0xff, 0x7f, 
	0x7e, 0xbf, 0xff, 0xff, 0xf7, 0xfb, 0xff, 0x7f, 0x7e, 0xbf, 0xff, 0xff, 0xf7, 0xfb, 0xff, 0x7f, 
	0x7e, 0xbf, 0x3f, 0xf0, 0xf7, 0xfb, 0xff, 0x7f, 0xfe, 0xc0, 0xdf, 0xef, 0x0f, 0xfc, 0xff, 0x7f, 
	0xfe, 0xff, 0xdf, 0xef, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xdf, 0xef, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xbf, 0xf7, 0x07, 0xf8, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0x7f, 
	0xfe, 0xff, 0x1f, 0xe0, 0xff, 0xfb, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xfe, 0xff, 0xfb, 0xff, 0x7f, 
	0xfe, 0xff, 0x7f, 0xfd, 0xf7, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xbf, 0xf3, 0xf7, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xdf, 0xef, 0x07, 0xf8, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xf7, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0x9f, 0xfe, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xe7, 0xfe, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0x9f, 0xfe, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0x07, 0xf8, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0x77, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0x77, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0x77, 0xfe, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0x8f, 0xf9, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 
	0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 
	0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 
	0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 
	0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 
	0x7f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff
};


// Ícone de alerta (16x16 pixels)
static const uint8_t warning_icon[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 
    0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0C, 0x1E, 0x1F, 0x1F,
    0x1F, 0x1F, 0x1E, 0x0C, 0x00, 0x00, 0x00, 0x00,
    
    // Exclamação (8x8 centralizado)
    0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18
};

// Ícone de seleção (8x8 pixels)
static const uint8_t selector_icon[] = {
    0xFF, 0x81, 0x81, 0x81, 
    0x81, 0x81, 0x81, 0xFF
};

// Ícone do buzzer (16x16 pixels)
static const uint8_t buzzer_icon[] = {
    0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0x70,
    0x38, 0x1C, 0x0E, 0x07, 0x03, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0E,
    0x1C, 0x38, 0x70, 0xE0, 0xC0, 0x80, 0x00, 0x00
};

// Ícone de temperatura (16x16 pixels)
static const uint8_t temp_icon[] = {
    0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xC0, 0x60,
    0x30, 0x18, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00,
    0x00, 0x00, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0x0F
};
void ssd1306_draw_bitmap(ssd1306_t *oled, const uint8_t *data, uint8_t x, uint8_t y, uint8_t w, uint8_t h);
void ssd1306_draw_rect(ssd1306_t *oled, uint8_t x, uint8_t y, uint8_t w, uint8_t h);
void draw_progress_bar(ssd1306_t *oled, uint8_t x, uint8_t y, uint8_t width, uint8_t height, float progress);
void ssd1306_fill_rect(ssd1306_t *oled, uint8_t x, uint8_t y, uint8_t w, uint8_t h);


#endif // SCREEN_H