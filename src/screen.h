/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * screen.h
 * Copyright (C) 2017 Vladimir Roncevic <elektron.ronca@gmail.com>
 * 
 * kernel is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * kernel is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __SCREEN_H
#define __SCREEN_H

#include "types.h"

struct screen {
	uint16_t *textmemptr;
	int32_t attrib;
	int32_t csr_x;
	int32_t csr_y;
};

extern struct screen screen_vid;

extern void init_video(void);
extern void move_csr(void);
extern void scroll(void);
extern void set_text_color(uint8_t forecolor, uint8_t backcolor);
extern void puts(uint8_t *text);
extern void putch(uint8_t c);
extern void cls(void);

#endif

