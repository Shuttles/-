/*************************************************************************
	> File Name: 2.0.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 16时01分53秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int n;
    char str[100];
    scanf("%[^\n]s", str);
    n = printf("%s", str);
    printf(" has %d digits\n", n);

    return 0;
}
