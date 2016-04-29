/*
 ============================================================================
 Name        : main.c
 Author      : gustavo
 Version     :
 Copyright   : Study project.
 Description : Study in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

int main(void) {
	int k = 0;
    double b = 5 % 3 & 4 + 5 * 6;
    int *p1 = NULL;
    int *p2 = NULL;
    int **p3 = NULL;
    int a1 = 0;

    printf("%lf\n", b);

    /*b = 3 % 0 * 1 - 4 / 2;*/ /*float exception. Divide by zero*/

    b = 3 && 5 & 4 % 3;

    printf("%lf\n", b);

    /* 0 + 2 + 2. k is 1 at end. */
    b = k++ + ++k + k--; /* undefined operation. Right option!*/
    printf("%lf\n", b);
    printf("k = %d\n", k);

    a1 = 3;
    p1 = &a1;
    printf("%d\n", *p1);

    a1 = 4;
    *p1 = a1;
    printf("%d\n", *p1);

    p2 = p1;
    printf("%d\n", *p2);

    a1 = 5;
    printf("%d\n", *p2);

    p3 = &p1;
    printf("%x\n", p1);

	return EXIT_SUCCESS;
}
