#include "./vga.h"

void kmain()
{
    kclear(0x07);
    kputs("ununennium is loading...", 0x07);
    kpanic();
    __asm__ volatile ("cli");
    __asm__ volatile ("hlt");

}