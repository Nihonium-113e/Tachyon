#include "./vga.h"

void kmain()
{
    kclear(0x07);
    __asm__ volatile ("cli");
    __asm__ volatile ("hlt");

}