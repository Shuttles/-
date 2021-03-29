/*************************************************************************
	> File Name: 2.c
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月29日 星期一 19时14分03秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int func(int **a){
    return a[1][3];
}

int main() {
    int a[10][100];
    a[1][3] = 641;
    printf("a[1][3] = %d\n", func(a));
    return 0;
}
