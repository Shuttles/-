/*************************************************************************
	> File Name: test.h
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月15日 星期一 15时44分38秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#define TEST(a, b) \
void a##_haizei_##b();\
__attribute__((constructor))\
void add##_haizei_##a##_haizei_##b() {\
    add_function(a##_haizei_##b, #a "_haizei_" #b);\
}\
void a##_haizei_##b()

#define EXPECT_EQ(a, b) printf("%s == %s ? %s\n", #a, #b, (a) == (b) ? "True" : "False");


typedef void (*TestFuncT)();

struct Function {
    TestFuncT func;
    const char *str;
};




int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);



#endif
