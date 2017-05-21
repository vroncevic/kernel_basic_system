/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * screen_scroll.c
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
#include "memory.h"

void scroll(void) {
	uint32_t blank, temp;
	blank = 0x20 | (screen_vid.attrib << 8);
	if(screen_vid.csr_y >= 25) {
		temp = screen_vid.csr_y - 25 + 1;
		memcpy(
			screen_vid.textmemptr,
			screen_vid.textmemptr + temp * 80,
			(25 - temp) * 80 * 2
		);
		memsetw(screen_vid.textmemptr + (25 - temp) * 80, blank, 80);
		screen_vid.csr_y = 25 - 1;
	}
}

