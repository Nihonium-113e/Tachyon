#include "./driver/vga.h"
#include "./driver/io.h"

void kmain()
{
    // testing all headers (should print 'ABC' with no cursor on screen)

    // test io.h
    koutb(0x3D4, 0x0A);
    koutb(0x3D5, 0x20);

    // test vga.h
    kclear(0x07);
    kputs("ABC", 0x07);

    __asm__ volatile ("cli");
    __asm__ volatile ("hlt");

}