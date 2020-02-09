/*************************************************************************
	> File Name: 4.my_printf.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月31日 星期三 13时26分47秒
 ************************************************************************/
//注意why const char???
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>


int reverse_num(int *x) {
    int cnt = 0, ans = 0;
    int temp = *x;
    do {
        ans = ans * 10 + temp % 10;
        temp /= 10;
        cnt++;
    } while (temp);
    *x = ans;
    return cnt;
}

int output_num(int num, int digit) {
    int cnt = 0;
    while (digit--) {
        putchar(num % 10 + '0');
        cnt++;
        num /= 10;
    }
    return cnt;
}


int my_printf(const char *frm, ...) {
    int cnt = 0;
    #define PUTC(a) putchar(a), ++cnt
    va_list arg;
    va_start(arg, frm);
    for (int i = 0; frm[i]; i++) {
        switch (frm[i]) {
            case '%': {
                switch (frm[++i]) {
                    case '%': PUTC(frm[i]); break;
                    case 'd': {
                        int xx = va_arg(arg, int);
                        uint32_t x;
                        if (xx < 0) {
                            PUTC('-');
                            x = -xx;
                        } else x = xx;
                        int num1 = x / 100000, num2 = x % 100000;
                        int digit1 = reverse_num(&num1), digit2 = reverse_num(&num2);
                        //printf("%d's digit1 = %d  ", num1, digit1);
                        //printf("%d's digit2 = %d  ", num2, digit2);
                        //思考一下为什么一定要加上下面两行？
                        //如果没加下面两行，输出的数之前总会多出个0?????
                        if (num1) digit2 = 5;
                        else digit1 = 0;
                        output_num(num1, digit1);
                        output_num(num2, digit2);
                        cnt += (digit1 + digit2);
                    } break;
                    case 's': {
                        const char *str = va_arg(arg, const char *);
                        for (int j = 0; str[j]; j++) {
                            PUTC(str[j]);
                        }
                    } break;
                }
            } break;
            default: PUTC(frm[i]);
        }
    }
    va_end(arg);
    #undef PUTC
    return cnt;
}



int main() {
    int a = 641;
    printf("hello world\n");
    my_printf("hello world\n");    
    printf("%s\n", "suiyuejinhao");
    my_printf("%s\n", "suiyuejinhao");
    printf("int(a) = %d\n", a);
    my_printf("int(a) = %d\n", a);
    printf("int(123) = %d\n", 123);
    my_printf("int(123) = %d\n", 123); 
    printf("int(-123) = %d\n", -123);
    my_printf("int(-123) = %d\n", -123);
    printf("int(1000) = %d\n", 1000);
    my_printf("int(1000) = %d\n", 1000);
    printf("int(0) = %d\n", 0);
    my_printf("int(0) = %d\n", 0);
    printf("INT32_MAX = %d\n", INT32_MAX);
    my_printf("INT32_MAX = %d\n", INT32_MAX);
    printf("INT32_MIN = %d\n", INT32_MIN);
    my_printf("INT32_MIN = %d\n", INT32_MIN);

    int n = 0;
    while (~scanf("%d", &n)) {
        printf(" has %d digits\n", printf("%d", n));
        my_printf(" has %d digits\n", my_printf("%d", n));
    }
    return 0;
}

