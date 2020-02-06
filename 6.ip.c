/*************************************************************************
	> File Name: 6.ip.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月15日 星期日 19时45分47秒
 ************************************************************************/

#include <stdio.h>

union IP {
    int num;
    struct {
        unsigned char a1;
        unsigned char a2;
        unsigned char a3;
        unsigned char a4;
    } ip;
};

int main() {
    IP p;
    char str[100];
    int a[4];
    while (~scanf("%s", str)) {
        sscanf(str, "%d.%d.%d.%d", a, a + 1, a + 2, a + 3);   
        p.ip.a1 = a[0];
        p.ip.a2 = a[1];
        p.ip.a3 = a[2];
        p.ip.a4 = a[3];
        printf("ip = %u\n", p.num);
    }
    return 0;
}
