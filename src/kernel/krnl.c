#include "./driver/vga.h"
#include "./driver/io.h"

void kmain()
{
    kcurset();
    kclear(0x07);
    int i=0;
    while(i==0){
        kput(kgetscan(), 0x07);
    }
    __asm__ volatile ("cli");
    __asm__ volatile ("hlt");

}