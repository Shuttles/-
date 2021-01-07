/*************************************************************************
	> File Name: 5.log.c
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年01月06日 星期三 11时17分51秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LOG(frm, args...) {\
    printf("[%s : %d] ", __func__, __LINE__);\
    printf(frm, ##args);\
}

int main() {
    int a = 7;
    LOG("%d\n", a);
    LOG("hello world!\n");
    return 0;
}
