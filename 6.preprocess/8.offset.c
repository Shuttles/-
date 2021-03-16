/*************************************************************************
	> File Name: 996.c
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月16日 星期二 16时31分29秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
#define offset(T, name) ({\
    T tmp;\
    (char *)&tmp.name - (char *)&tmp;\
})
*/
 
#define offset(T, name) &(((T*)(0))->name)

struct Data {
    double a;
    int b;
    char c;
};

int main() {
    printf("a : %d\n", offset(struct Data, a));
    printf("b : %d\n", offset(struct Data, b));
    printf("c : %d\n", offset(struct Data, c));
    return 0;
}
