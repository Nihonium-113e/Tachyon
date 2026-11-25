BLD=./bld
SRC=./src
KRNL=./src/kernel

always: ununennium

ununennium: ${BLD}/*.o
	ld -T link.ld -m elf_i386 ${BLD}/load.o ${BLD}/krnl.o ${BLD}/vga.o -o ununennium

${BLD}/krnl.o: ${KRNL}/krnl.c
	i686-elf-gcc -c ${KRNL}/krnl.c -o ${BLD}/krnl.o

${BLD}/vga.o: ${KRNL}/vga.o
	i686-elf-gcc -c ${KRNL}/vga.c -o ${BLD}/vga.o

${BLD}/load.o: ${SRC}/boot/load.s
	nasm -f elf32 ${SRC}/boot/load.s -o ${BLD}/load.o
