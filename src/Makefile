#
# @brief   Main entry point of make process
# @version ver.1.0
# @date    Sun May 21 22:11:00 CEST 2017
# @company None, free software to use 2017
# @author  Vladimir Roncevic <elektron.ronca@gmail.com>
#

include compiler.mk
include assembler.mk
include linker.mk
include objects.mk

all: $(OBJECTS) kernel.bin kernel.iso

%.o: %.c
	@echo
	@echo Compiling module $<
	gcc $(GCC_FLAGS) -o $@ -c $<

loader.o: loader.asm
	@echo
	@echo Compiling module $<
	nasm $(NASM_FLAGS) -o $@ $<

kernel.bin: link.ld
	@echo
	@echo Linking modules
	ld $(LD_FLAGS) -T $< -o $@ $(OBJECTS)

kernel.iso: kernel.bin
	@echo
	@mkdir iso
	@mkdir iso/boot
	@mkdir iso/boot/grub
	@cp $< iso/boot/$<
	@echo 'set timeout=0'                     > iso/boot/grub/grub.cfg
	@echo 'set default=0'                     >> iso/boot/grub/grub.cfg
	@echo ''                                  >> iso/boot/grub/grub.cfg
	@echo 'menuentry "MyOS" {'                >> iso/boot/grub/grub.cfg
	@echo '  multiboot /boot/kernel.bin'      >> iso/boot/grub/grub.cfg
	@echo '  boot'                            >> iso/boot/grub/grub.cfg
	@echo '}'                                 >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=$@ iso
	@chmod 755 $@
	@rm -rf iso

run: kernel.iso
	@echo
	(killall VirtualBox && sleep 1) || true
	VirtualBox --startvm "MyOS" &
	@echo

clean:
	@echo
	rm -f $(OBJECTS) *.bin *.iso
	@echo

