/*************************************************************************
	> File Name: 3.maxint.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  2/ 8 19:18:26 2020
 ************************************************************************/

#include<iostream>
#include <stdarg.h>
using namespace std;

int max_int(int num, ...) {
    if (num < 0) return 0;
    int ans = 0, temp;
    va_list arg;
    va_start(arg, num);
    while (num--) {
        temp = va_arg(arg, int);
        if (temp > ans) ans = temp;
    }
    va_end(arg);
    return ans;
}


int main() {
    printf("max_int(3, 1, 5, 3) = %d\n", max_int(3, 1, 5, 3));
    printf("max_int(2, 1, 3) = %d\n", max_int(2, 1, 3));
    printf("max_int(6, 6, 5, 3, 7, 9, 10) = %d\n", max_int(6, 6, 5, 3, 7, 9, 10));
    printf("max_int(3, 1, 9, 10) = %d\n", max_int(3, 1, 9, 10));
    return 0;
}
