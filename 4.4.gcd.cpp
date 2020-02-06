/*************************************************************************
	> File Name: 4.4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月29日 星期一 18时24分18秒
 ************************************************************************/

#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;//这是递归程序的边界条件
    return gcd(b, a % b);
}

/*
int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}
*/

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;

    return 0;
}
