/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * screen_putch.c
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
#include "screen.h"

void putch(uint8_t c) {
	uint16_t *where;
	uint32_t att = screen_vid.attrib << 8;
	if(c == 0x08) {
		if(screen_vid.csr_x != 0) {
			screen_vid.csr_x--;
		}
	} else if(c == 0x09) {
		screen_vid.csr_x = (screen_vid.csr_x + 8) & ~(8 - 1);
	} else if(c == '\r') {
		screen_vid.csr_x = 0;
	} else if(c == '\n') {
		screen_vid.csr_x = 0;
		screen_vid.csr_y++;
	} else if(c >= ' ') {
		uint16_t location = (screen_vid.csr_y * 80 + screen_vid.csr_x);
		where = screen_vid.textmemptr + location;
		*where = c | att;
		screen_vid.csr_x++;
	}
	if(screen_vid.csr_x >= 80) {
		screen_vid.csr_x = 0;
		screen_vid.csr_y++;
	}
	scroll();
	move_csr();
}

