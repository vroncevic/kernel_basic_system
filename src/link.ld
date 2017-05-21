/**
 *
 * @brief   Linking process
 * @version ver.1.0
 * @date    Sun May 21 22:11:00 CEST 2017
 * @company None, free software to use 2017
 * @author  Vladimir Roncevic <elektron.ronca@gmail.com>
 *
 **/

OUTPUT_FORMAT("binary")
ENTRY(loader)
phys = 0x00100000;
SECTIONS
{
	.text phys : AT(phys) {
		code = .;
		*(.text)
		*(.rodata)
		. = ALIGN(4096);
	}

	.data : AT(phys + (data - code)) {
		data = .;
		*(.data)
		. = ALIGN(4096);
	}

	.bss : AT(phys + (bss - code)) {
		bss = .;
		*(.bss)
		. = ALIGN(4096);
	}

	end = .;
}

