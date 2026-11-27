BLD=./bld
SRC=./src
KRNL=./src/kernel

always: tachyon

tachyon: ${BLD}/load.o ${BLD}/krnl.o ${BLD}/vga.o
	ld -T link.ld -m elf_i386 ${BLD}/load.o ${BLD}/krnl.o ${BLD}/vga.o -o tachyon

${BLD}/krnl.o: ${KRNL}/krnl.c
	gcc -m32 -ffreestanding -nostdlib -nostartfiles -c ${KRNL}/krnl.c -o ${BLD}/krnl.o

${BLD}/vga.o: ${KRNL}/driver/vga.c
	gcc -m32 -ffreestanding -nostdlib -nostartfiles -c ${KRNL}/driver/vga.c -o ${BLD}/vga.o

${BLD}/load.o: ${SRC}/boot/load.s
	nasm -f elf32 ${SRC}/boot/load.s -o ${BLD}/load.o

${BLD}/io.o: ${KRNL}/driver/io.s
	nasm -f elf32 ${KRNL}/driver/io.s -o ${BLD}/io.o

clean:
	rm -rf tachyon
	rm -rf ${BLD}/*
