/*************************************************************************
	> File Name: 6.helloworld.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月16日 星期一 19时20分45秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>


int main() {
    char string[5] = {'h', 'e', 'l', 'l', 'o'};
    int len = strlen(string);
    printf("%s\n", string);    
    printf("strlen(string) = %d\n", len);
    return 0;
}
