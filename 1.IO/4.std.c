/*************************************************************************
	> File Name: 4.printf.c
	> Author: 
	> Mail: 
	> Created Time: 四  2/ 6 21:50:03 2020
 ************************************************************************/
//linux中一切皆文件！！！
//stdin stdout stderr里存的是三个文件指针的地址！！！！
#include <stdio.h>

int main() {
    int n;
    printf("EOF = %d  stdin = %d stdout = %d stderr = %d\n", EOF, stdin, stdout, stderr);
    return 0;
}
