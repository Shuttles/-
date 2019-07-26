/*************************************************************************
	> File Name: 3.1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月26日 星期五 20时46分57秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (!n) {
        printf("FOOLISH\n");
    } else if (n < 60) {
        printf("FAIL\n");
    } else if (n < 75) {
        printf("MEDIUM\n");
    } else {
        printf("GOOD\n");
    }
    return 0;
}
