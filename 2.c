/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 15时36分34秒
 ************************************************************************/

#include<stdio.h>
int main() {
    char str[100];
    while (scanf("%[^\n]s",str) != EOF) {
        getchar();
        printf(" has %d chars\n", printf("%s", str));
    } 
    return 0;
}
