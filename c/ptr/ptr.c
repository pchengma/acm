/*
 * test4.c
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a = (int *) malloc(sizeof(int) * 2);
    a[0] = 1;
    a[1] = 2;
    printf("%d\n", a[1]);
    printf("%d\n", &(a[0]));
    printf("%d\n", &(a[1]));
    int *b = a;
    printf("%d\n", b);
    *b++;
    printf("%d\n", b);
    b += 32;
    printf("%d\n", b);
}
