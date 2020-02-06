/*************************************************************************
	> File Name: 6.16-digits.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月16日 星期一 20时10分50秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    int x;
    char str[10];
    while (~scanf("%d", &x)) {
        //sprintf(str, "%x", x);
        //printf("%s has %lu digits\n", str, strlen(str));
        printf("%s has %d digits\n",str, sprintf(str, "%x", x)) ;
    }
    return 0;
}
