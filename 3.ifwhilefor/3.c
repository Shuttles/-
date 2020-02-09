/*************************************************************************
	> File Name: 3.0.3.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月26日 星期五 21时30分32秒
 ************************************************************************/
//骚操作之将字符'0'~'9'转化为数字0~9(原理：－４８或者－‘０’即可)
#include<stdio.h>

int main() {
    char x;
    scanf("%c", &x);
    switch (x) {
        case '0': printf("%d\n", '0' & 15);break;
        case '1': printf("%d\n", '1' & 15);break;
        case '2': printf("%d\n", '2' & 15);break;
        case '3': printf("%d\n", '3' & 15);break;
        case '4': printf("%d\n", '4' & 15);break;
        case '5': printf("%d\n", '5' ^ 48);break;
        case '6': printf("%d\n", '6' ^ 48);break;
        case '7': printf("%d\n", '7' ^ 48);break;
        case '8': printf("%d\n", '8' ^ 48);break;
        case '9': printf("%d\n", '9' ^ 48);break;
        default : printf("error\n");break;
    }


    return 0;
}
//(& 15)是取出二进制后四位，(^ 48)是去除二进制前两位
