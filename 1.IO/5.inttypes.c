/*************************************************************************
	> File Name: 5.inttypes.c
	> Author: 
	> Mail: 
	> Created Time: 五  2/ 7 19:28:29 2020
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int main() {
    int a = 123;
    printf("%d\n", a);
    printf("%x\n", a);
    printf("%X\n", a);
    printf("%o\n", a);
    printf("%s\n", PRId8);
    printf("%s\n", PRId16);
    printf("%s\n", PRId32);
    printf("%s\n", PRId64);
    printf("%s\n", PRIx8);
    printf("%s\n", PRIx16);
    printf("%s\n", PRIx32);
    printf("%s\n", PRIx64);
    printf("%s\n", PRIo8);
    printf("%s\n", PRIo16);
    printf("%s\n", PRIo32);
    printf("%s\n", PRIo64);
    return 0;
}
