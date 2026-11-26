#include "./vga.h"

volatile unsigned char* VGA = (volatile unsigned char*)0xB8000;

#define WIDTH 80
#define HEIGHT 25
#define INDEX ((WIDTH*y)+x)*2

volatile unsigned int x=0;
volatile unsigned int y=0;

int kpanic() {
    kclear(0x17);
    y=5;
    kputs("                             === KERNEL PANIC!! ===                             \n", 0x71);
    kput('\n', 0x17);
    kputs("         An error has ocurred and the system has halted itself to protect       \n", 0x17);
    kputs("                    your data, please turn off your computer.                   \n", 0x17);
    kput('\n', 0x17);
    kputs("                                   No signal.                                     ", 0x17);
} 

int kputs(char *str, int col) {
    for(int i=0; str[i]!='\0'; i++) { 
        kput(str[i], col);
    }
    return 0;
}

int kput(char c, int color) {
    if(c=='\n') {
        if(y>=25)
        {
            return 0;
        } else {
            x=0;
            y++;
        }
    } else {
        VGA[INDEX] = c;
        VGA[INDEX+1] = color;
        x++;
        return 0;
    }
    
}

int kclear(int color) {
    x=0;
    y=0;
    for(int i=0; i<=80; i++) {
        for(int j=0; j<=25; j++){
            kput(' ', color);
        }
    }
    x=0;
    y=0;
    return 0;
}
