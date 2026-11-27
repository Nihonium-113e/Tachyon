#include "./vga.h"
#include "./io.h"

volatile unsigned char* VGA = (volatile unsigned char*)0xB8000;

#define WIDTH 80
#define HEIGHT 25
#define INDEX ((WIDTH*y)+x)*2

volatile unsigned int x=0;
volatile unsigned int y=0;

void kcurset() {
    outb(0x3D4, 0x0A);
    outb(0x3D5, 0x20);
}

char kgetscan() {
    while((inb(0x64) & 0x01)==0){

    }
    if(inb(0x60)==0x19){
        kpanic("Manual Crash");
        __asm__ volatile ("cli");
        __asm__ volatile ("hlt");
    } else {
        return inb(0x60);
    }
}

void kpanic(char *str) {
    kclear(0x17);
    y=5;
    kputs("                             === KERNEL PANIC!! ===                             \n", 0x71);
    kput('\n', 0x17);
    kputs("         An error has ocurred and the system has halted itself to protect       \n", 0x17);
    kputs("                    your data, please turn off your computer.                   \n", 0x17);
    kput('\n', 0x17);
    kputs("                                   No signal.                                     ", 0x17);
    kputs("\n\n\n\n\n\n\n\n\n\n\n\n\n\n", 0x17);
    kputs("Error: ", 0x17);
    kputs(str, 0x17);
}

void kputs(char *str, int col) {
    for(int i=0; str[i]!='\0'; i++) { 
        kput(str[i], col);
    }
}

void kput(char c, int color) {
    if(c=='\n') {
        if(y>=24)
        {
            kscroll();
        } else {
            x=0;
            y++;
        }
    } else {
        VGA[INDEX] = c;
        VGA[INDEX+1] = color;
        x++;
        
    }
    
}

void kclear(int color) {
    x=0;
    y=0;
    for(int i=0; i<=80; i++) {
        for(int j=0; j<=25; j++){
            kput(' ', color);
        }
    }
    x=0;
    y=0;
}

void kcharmov(int sx, int sy, int fx, int fy){
    VGA[((WIDTH*fy)+fx)*2]=VGA[((WIDTH*sy)+sx)*2];
    VGA[((WIDTH*fy)+fx)*2+1]=VGA[((WIDTH*sy)+sx)*2+1];
    VGA[((WIDTH*sy)+sx)*2]=' ';
    VGA[((WIDTH*sy)+sx)*2+1]=0x07;
}
void klinemov(int sy, int fy){
    for(int i=0; i<WIDTH; i++){
        kcharmov(i, sy, i, fy);
    }
}

void kscroll(){
    for(int i=0; i<HEIGHT; i++){
        klinemov(i+1, i);
    }
    x=0;
}