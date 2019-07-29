/*************************************************************************
	> File Name: 3.0.2.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月26日 星期五 21时06分46秒
 ************************************************************************/
//题目：随机生成１０个０～９９之间的数，输出偶数的个数
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int value;
    int i;
    int count = 0;
    for (i = 0; i < 10; i++) {
        value = rand() % 100;
        i && printf(" ");
        printf("%d", value);
        count  += !(value & 1);//(value % 2)等价于(value & 1)
    }
    printf("\n%d\n", count);
    return 0;
}
