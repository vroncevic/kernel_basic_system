/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * screen_cls.c
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

void cls(void) {
	uint32_t blank;
	int32_t i;
	blank = 0x20 | (screen_vid.attrib << 8);
	for(i = 0; i < 25; i++) {
		memsetw(screen_vid.textmemptr + i * 80, blank, 80);
	}
	screen_vid.csr_x = 0;
	screen_vid.csr_y = 0;
	move_csr();
}

