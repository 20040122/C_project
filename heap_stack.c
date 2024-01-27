#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char *printf_stack() {
    char c[100]="printf_stack print_stack";
    char *p;
    p=c;
    puts(p);
    return p;
}
char *printf_heap() {
    char *p;
    p=(char *)malloc(100);
    strcpy(p, "printf_heap print_heap");
    puts(p);
    return p;
}
int main() {
    char *p;
    p= printf_stack();
    puts(p);
    p= printf_heap();
    puts(p);
    return 0;
}

