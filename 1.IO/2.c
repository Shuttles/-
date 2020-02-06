/*************************************************************************
	> File Name: 1.2.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月24日 星期三 12时07分25秒
 ************************************************************************/

#include<stdio.h>
int main() {
    char str[100];
    int ret;
    while ((ret = scanf("%[^\n]s", str)) != EOF) {//当当前字符不是\n是就一直读入！！！！
        getchar();//吸收掉换行
        printf(" has %d chars\n", printf("%s", str));
        printf("ret = %d\n", ret);
    }
    return 0;
}
