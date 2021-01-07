/*************************************************************************
	> File Name: 1.c
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年10月25日 星期日 21时07分48秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

/*cppreference中的例子
// tgmath.h 宏 cbrt 的可能实现
#define cbrt(X) _Generic((X), \
              long double: cbrtl, \
                  default: cbrt,  \
                    float: cbrtf  \
)(X)
*/


#define TYPE(X) _Generic((X),\
    int : "int",\
    double : "double"\
)

int main()
{
    int a = 2020;
    double b = 996.996;
    //printf("__typeof(a) = " TYPE(a) "\n");
    //printf("__typeof(b) = " TYPE(b) "\n");
    //so，结论就是，下一行是对的，而上面两行是错的，不懂为啥。。。
    //难道是只在运行时才计算什么类型？
    printf(TYPE(a));
    printf("\n");
    printf(TYPE(b));
    printf("\n");
    return 0;
}
