/*************************************************************************
	> File Name: 5.define.log.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月15日 星期日 10时05分47秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

#define COLOUR(a, b) "\033[1;" #b "m" a "\033[0m"
#define RED(a) COLOUR(a, 31)
#define GREEN(a) COLOUR(a. 32)
#define YELLOW(a) COLOUR(a, 33)
#define BLUE(a) COLOUR(a, 34)
#define VIOLET(a) COLOUR(a, 35)

#ifndef DEBUG
#define log(frm, args...) {\
    printf("\033[47;31m[%s : %d] \033[0m", __func__, __LINE__);\
    printf(frm, ##args);\
    printf("\n");\
}    //这样看做连接内容就允许args为空，如果不加##则把args当成了宏中的参数，就不允许为空了，
#else 
#define log(frm, args...)
#endif

#define __contact(a, b) a##b
#define contact(a, b) __contact(a, b)

#define ABS(x) _Generic((x),\
    int : abs(x),\
    double : fabs(x),\
    default : fabs(x)\
)
using namespace std;

int main() {
    int a = 6;
    log(BLUE("%d"), a)
    log(RED("hello") YELLOW(" world"))
    log(BLUE("三十年河东，") VIOLET("三十年河西 ") RED("莫欺少年穷"))

    int abcdef = 1;
    contact(abc, def) = 2;
    log(YELLOW("%d"), abcdef)
    contact(contact(ab,c), contact(de,f)) = 3;
    log(BLUE("%d"), abcdef)

    int temp1 = -123;
    double temp2 = -456.789;
    log("|temp1| : %d", ABS(temp1))
    log("|temp2| : %lf", ABS(temp2))
    return 0;
}
