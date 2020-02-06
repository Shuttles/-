/*************************************************************************
	> File Name: 1.Tprintf.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月24日 星期三 17时11分46秒
 ************************************************************************/

#include<stdio.h>
#define swap(a, b) {\
     __typeof(a) temp = a;\
    a = b, b = temp;\
  }

int main() {
    int n;
    scanf("%d", &n);
    char str[100];
    char buff[100];
    char *p = str, *q = buff;
    sprintf(str, "%d.%d.%d.%d",192, 168, 1, 10);
    printf("str = %s\n", str);
    if (n & 1){
        sprintf(q, "(%s)", p);
        swap(p, q);
    }
    if (n & 2) {
        sprintf(q, "[%s]", p);
        swap(p, q);
    }
    if (n & 4) {
        sprintf(q, "{%s}", p);
        swap(p, q);
    }
    //printf("%s\n", str);这是错的！！！
    printf("%s\n", p);//这才是对的！说明p最后一定不指向str!!!!
    return 0;
}
