#ifndef VGA_H
#define VGA_H

char kgetscan();
void kcurset();                                         // enables or disables screen cursor
void kscroll();                                         // moves the screen one line up
void klinemov(int sy, int fy);                          // moves a single line from a start y coordinate (sy) to a final y coordinate (fy)
void kcharmov(int sx, int sy, int fx, int fy);          // moves a single character from a start coordinate (sx, sy) to a final coordinate (fx, fy) 
void kpanic(char *str);                                          // kernel panic
void kputs(char *str, int color);                       // prints a string to screen with a set color
void kput(char c, int color);                           // prints a character to the screen with a set color
void kclear(int color);                                 // clear the screen with a set color

#endif