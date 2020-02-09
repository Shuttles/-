/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  2/ 8 17:49:34 2020
 ************************************************************************/

#include<iostream>
using namespace std;

int f1(int n) {
    if (n == 0) return 1;
    return n * f1(n - 1);
}

int f2(int n) {
    return n * (n + 1) / 2;
}


void g(int (*f)(int), int x) {
    printf("g(%d) = %d\n", x, f(x));
    return;
}


int main() {
    g(f1, 5);
    g(f2, 5);
    return 0;
}
