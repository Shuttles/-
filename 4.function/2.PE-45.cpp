/*************************************************************************
	> File Name: 2.PE-45.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  2/ 8 17:54:32 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
using namespace std;

int64_t Triangle(int64_t x) {
    return x * (x + 1) / 2;
}

int64_t Pentagonal(int64_t x) {
    return x * (3 * x - 1) / 2;
}

int64_t Hexagonal(int64_t x) {
    return x * (2 * x - 1);
}

int64_t binary_search(int64_t (*func)(int64_t), int64_t x) {
    int64_t head = 1, tail = x, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) return mid;
        if (func(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}


int main() {
    int n = 144;
    for (;;n++) {
        if (binary_search(Triangle, Hexagonal(n)) == -1) continue;
        if (binary_search(Pentagonal, Hexagonal(n)) == -1) continue;
        printf("%" PRId64 "\n", Hexagonal(n));
        break;
    }
    return 0;
}
