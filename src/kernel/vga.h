#ifndef VGA_H
#define VGA_H

void kscroll();
void kscrmovl(int sy, int fy);
void kscrmov(int sx, int sy, int fx, int fy);
void kpanic();
void kputs(char *str, int color);
void kput(char c, int color);
void kclear(int color);

#endif