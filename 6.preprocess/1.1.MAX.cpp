/*************************************************************************
	> File Name: 5.define.max.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月14日 星期六 22时34分45秒
 ************************************************************************/

#include <iostream>
#define MAX(a, b) ({\
    __typeof(a) _a = a;\
    __typeof(b) _b = b;\
    _a > _b ? _a : _b;\
})
#ifndef DEBUG
#define P(a) \
        printf("[%s : %s : %d] %s = %d\n", __FILE__, __func__, __LINE__, #a, a);
#else 
#define P(a)
#endif

using namespace std;

int main() {
    int a = 7;
    P(MAX(2, 3))
    P(5 + MAX(2, 3))
    P(MAX(2, MAX(3, 4)))
    P(MAX(2, 3 > 4 ? 3 : 4))
    P(MAX(a++, 6))
    P(a);
    return 0;
}
