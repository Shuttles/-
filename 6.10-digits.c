/*************************************************************************
	> File Name: 000.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月16日 星期一 20时23分50秒
 ************************************************************************/

#include <stdio.h>
#define log(frm, args...) {\
    printf("[%s : %s : %d] ", __FILE__, __func__, __LINE__);\
    printf(frm, ##args);\
    printf("\n");\
}

int main() {
    int x;
    while (~scanf("%d", &x)) {
        log(" has %d digits\n", printf("%d", x))
    }
    return 0;
}
