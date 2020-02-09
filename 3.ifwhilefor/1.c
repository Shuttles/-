/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: 六  2/ 8 12:47:49 2020
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(0));//初始化随机种子
    int a, b;
    scanf("%d%d", &a, &b);
    if (a - b) {
        printf("not equal\n");
    } else {
        printf("equal\n");
    }
    
    if ((a++) && (b++)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    if ((a++) || (b++)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    printf("a = %d, b = %d\n", a, b);

    for (int i = 0; i < 10; i++) {
        i && printf(" ");
        printf("%d", i);
    }
    printf("\n");

    int cnt;
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        i && printf(" ");
        printf("%d", val);
        cnt += !(val & 1);
    }
    printf("\n");
    printf("even num: %d\n", cnt);

    int n, digit = 0;
    scanf("%d", &n);
    do {
        digit += 1;
        n /= 10;
    } while (n);
    printf("digit = %d\n", digit);
    return 0;
}
