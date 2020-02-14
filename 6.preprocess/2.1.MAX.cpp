/*************************************************************************
	> File Name: 3.max.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  2/10 14:49:12 2020
 ************************************************************************/

#include <iostream>
#define MAX(a, b) ({\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    _a > _b ? _a : _b;\
})
#define P(a) {\
    printf("%s = %d\n", #a, a);\
}

int main() {
    int a = 7;
    P(MAX(2, 3));
    P(5 + MAX(2, 3));
    P(MAX(2, MAX(3, 4)));
    P(MAX(2, 3 > 4 ? 3 : 4));
    P(MAX(a++, 6));
    P(a);
    return 0;
}
