/*************************************************************************
	> File Name: 4.3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月29日 星期一 11时59分57秒
 ************************************************************************/

#include <iostream>
#include <cinttypes>
#include <cstdio>
using namespace std;

int64_t Triangle(int64_t n) {
    return n * (n + 1) / 2;
}

int64_t Pentagonal(int64_t n) {
    return n * (3 * n - 1) / 2;
}

int64_t Hexagonal(int64_t n) {
    return n * (2 * n - 1);
}

int64_t binary_search(int64_t (*func)(int64_t), int64_t y) {
    int64_t head = 1, tail = y, mid;
    while (head <= tail) {
        mid = (head + tail) / 2;
        if (func(mid) == y) return mid;
        if (func(mid) < y) head = mid + 1;
        if (func(mid) > y) tail = mid - 1;
    }
    return -1;
}

int main() {
    int  n = 144;
    for (; ; n++) {
        if (binary_search(Triangle, Hexagonal(n)) == -1) continue;
        if (binary_search(Pentagonal, Hexagonal(n)) == -1) continue;
        printf("%" PRId64 "\n",Hexagonal(n));
        break;
    }
    return 0;
}
