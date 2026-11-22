#!/bin/bash

rm -rf ./bld
mkdir ./bld

nasm -f elf32 ./src/boot/load.s -o ./bld/load.o

i686-elf-gcc -c ./src/kernel/krnl.c -o ./bld/krnl.o

ld -T link.ld -m elf_i386 ./bld/load.o ./bld/krnl.o -o ./iso/boot/tsix.elf