/*************************************************************************
	> File Name: swap.2.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 16时51分04秒
 ************************************************************************/
//用宏去swap是最快的
#include <stdio.h>

#define swap(a, b) {\
    __typeof(a) temp = a;\
    a = b; b = temp;\
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    swap(a, b);
    printf("%d %d\n", a, b);
    return 0;
}
