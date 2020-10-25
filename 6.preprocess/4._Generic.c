/*************************************************************************
	> File Name: 3._Generic.c
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年10月25日 星期日 21时24分30秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#define getTypeName(x) _Generic((x), _Bool:"_Bool",\
    char: "char", \
    signed char: "signed char", \
    unsigned char: "unsigned char", \
    short int: "short int", \
    unsigned short int: "unsigned short int", \
    int: "int", \
    unsigned int: "unsigned int", \
    long int: "long int", \
    unsigned long int: "unsigned long int", \
    long long int: "long long int", \
    unsigned long long int: "unsigned long long int", \
    float: "float", \
    double: "double", \
    long double: "long double", \
    char *: "pointer to char", \
    void *: "pointer to void", \
    int *: "pointer to int")

int main()
{
    char c = 'a';
    size_t s;
    ptrdiff_t p;
    intmax_t i;
    int arr[3] = { 0 };
    printf("s is '%s'\n", getTypeName(s));
    printf("p is '%s'\n", getTypeName(p));
    printf("i is '%s'\n", getTypeName(i));
    printf("c is '%s'\n", getTypeName(c));
    printf("arr is '%s'\n", getTypeName(arr));
    printf("0x7FFFFFFF is '%s'\n", getTypeName(0x7FFFFFFF));
    printf("0xFFFFFFFF is '%s'\n", getTypeName(0xFFFFFFFF));
    printf("0x7FFFFFFFU is '%s'\n", getTypeName(0x7FFFFFFFU));
}
