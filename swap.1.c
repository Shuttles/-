/*************************************************************************
	> File Name: swap.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 16时39分15秒
 ************************************************************************/
//用异或运算去swap,但这还不是最快的交换算法
#include<stdio.h>

void swap(int *a, int *b);

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    swap(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return ;
}
