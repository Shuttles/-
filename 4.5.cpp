/*************************************************************************
	> File Name: 4.5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月29日 星期一 18时31分02秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int ex_gcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int xx, yy, ret = ex_gcd(b, a % b, &xx, &yy);
    *x = yy;
    *y = xx - a / b * yy;
    return ret;
}

int main() {
    int a, b;
    cin >> a >> b;
    int x, y;
    ex_gcd(a, b, &x, &y);
    printf("%d * %d + %d * %d = %d\n", a, x, b, y, a * x + b * y);
    return 0;
}
