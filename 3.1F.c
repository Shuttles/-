/*************************************************************************
	> File Name: 0.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月24日 星期三 21时33分00秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("FOOLISH\n");
    } else if (n > 0 && n < 60) {
        printf("FAIL\n");
    } else if (n >= 60 && n < 75) {
        printf("MEDIUM\n");
    } else if (n >= 75 && n <= 100) { 
        printf("GOOD\n");
    }
    return 0;
}
