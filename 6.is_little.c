/*************************************************************************
	> File Name: 6.is_little.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月16日 星期一 22时04分11秒
 ************************************************************************/

#include <stdio.h>

int is_little() {
     int x = 1;
    return ((char *)&x)[0];
}


int main() {
    is_little() && printf("小端机\n");    
    (!is_little()) && printf("大端机\n");
    return 0;
}
