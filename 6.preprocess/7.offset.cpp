/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  1/ 9 22:10:52 2021
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

//新手写法

//不强转就不行！
//但是也不必两个强转成同一指针类型
//很神奇 原来不强转报错struct *和另外一个*不可以相减
//但是char *和long long却可以相减
#define offset(T, name) ({\
    T tmp;\
    (char *)&tmp.name - (long long)&tmp;\
}) 

//进阶写法
#define offset(T, name) (&(((T *)(0))->name))

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
