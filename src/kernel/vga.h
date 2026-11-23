#ifndef VGA_H
#define VGA_H

int kpanic();
int kputs(char *str, int color);
int kput(char c, int color);
int kclear(int color);

#endif