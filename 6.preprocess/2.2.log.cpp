/*************************************************************************
	> File Name: 4.log.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  2/10 16:39:45 2020
 ************************************************************************/

#include <stdio.h>


#define COLOR(a, b) "\033[1;" #b "m" a "\033[0m"
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define GREEN(a) COLOR(a, 32)
#define YELLOW(a) COLOR(a, 33)


#ifndef DEBUG

#define log(frm, args...) {\
    printf("\033[1;31m[%s : %s : %d] \033[0m  ", __FILE__, __func__, __LINE__);\
    printf(frm, ##args);\
}

#else 

#define log(frm, args...);

#endif

int main() {
    int a = 7;
    log(BLUE("a = %d\n"), a);
    log(GREEN("hello") " " YELLOW("world\n"));
    return 0;
}
