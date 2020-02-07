/*************************************************************************
	> File Name: 2.2.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 19时23分42秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main() {
    double  x;
    scanf("%lf", &x);
    double  y;
    y = x / 360 * 2 * acos(-1);
    printf("%f", y);
    return 0;
}
