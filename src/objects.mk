#
# @brief   List of object files
# @version ver.1.0
# @date    Sun May 21 22:11:00 CEST 2017
# @company None, free software to use 2017
# @author  Vladimir Roncevic <elektron.ronca@gmail.com>
#

OBJECTS = \
	loader.o \
	main.o \
	memcpy.o \
	memset.o \
	memsetw.o \
	strlen.o \
	inportb.o \
	outportb.o \
	screen_init_video.o \
	screen_puts.o \
	screen_set_text_color.o \
	screen_putch.o \
	screen_cls.o \
	screen_move_csr.o \
	screen_scroll.o \
	gdt_set_gate.o \
	gdt_install.o \
	idt_set_gate.o \
	idt_install.o \
	isrs_fault_handler.o \
	isrs_install.o \
	irq_handler.o \
	irq_install.o \
	irq_install_handler.o \
	irq_remap.o \
	irq_uninstall_handler.o \
	timer_install.o \
	timer_handler.o \
	timer_wait.o \
	keyboard_handler.o \
	keyboard_install.o

