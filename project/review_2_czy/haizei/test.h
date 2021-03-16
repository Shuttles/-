/*************************************************************************
	> File Name: test.h
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月15日 星期一 20时21分28秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#include <haizei/linklist.h>


#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"

#define RED(a) COLOR(a, 31)
#define GREEN(a) COLOR(a, 32)
#define YELLOW(a) COLOR(a, 33)
#define BLUE(a) COLOR(a, 34)
#define PURPLE(a) COLOR(a, 35)
#define CYAN(a) COLOR(a, 36)

#define RED_HL(a) COLOR_HL(a, 31)
#define GREEN_HL(a) COLOR_HL(a, 32)
#define YELLOW_HL(a) COLOR_HL(a, 33)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define PURPLE_HL(a) COLOR_HL(a, 35)
#define CYAN_HL(a) COLOR_HL(a, 36)

#define TEST(a, b) \
void a##_shuttles_##b();\
__attribute__((constructor))\
void add##a##_shuttles_##b() {\
    add_function(a##_shuttles_##b, #a "." #b);\
}\
void a##_shuttles_##b()

//失败了，没用
#define STR(a) ({\
    char str[100];\
    sprintf(str, "%s", (a));\
    str;\
})

#define EXPECT(a, b, comp) {\
    printf(GREEN("[-----------] ") #a " " #comp " " #b);\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    printf(" %s\n", (_a comp _b) ? GREEN_HL("TRUE") : RED_HL("FALSE"));\
    test_info.total += 1;\
    if (_a comp _b) test_info.success += 1;\
    else {\
        printf("\n");\
        printf(YELLOW_HL("\t%s : %d : Failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpect: " #a " " #comp " " #b));\
        printf(YELLOW_HL(" actual: "   " vs "  "\n"));\
        printf("\n");\
    }\
}


#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)

typedef void (*TestFuncT)();

struct Function {
    TestFuncT func;
    const char *str;
    struct LinkNode p;//链表外骨骼
};

struct TestInfo {
    int total, success;
};

extern struct TestInfo test_info;

int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);

#endif
