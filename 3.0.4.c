/*************************************************************************
	> File Name: 3.0.4.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月26日 星期五 21时39分41秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    do {
        sum++;
        n /= 10;
    }while (n);
    printf("has %d digits\n", sum);
    return 0;
}
