/*************************************************************************
	> File Name: test.h
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月15日 星期一 20时21分28秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"

#define RED(a) COLOR(a, 31)
#define GREEN(a) COLOR(a, 32)
#define BLUE(a) COLOR(a, 33)
#define YELLOW(a) COLOR(a, 34)


#define RED_HL(a) COLOR_HL(a, 31)
#define GREEN_HL(a) COLOR_HL(a, 32)
#define BLUE_HL(a) COLOR_HL(a, 33)
#define YELLOW_HL(a) COLOR_HL(a, 34)

#define TEST(a, b) \
void a##_shuttles_##b();\
__attribute__((constructor))\
void add##a##_shuttles_##b() {\
    add_function(a##_shuttles_##b, #a "." #b);\
}\
void a##_shuttles_##b()


#define EXPECT(a, b, comp) {\
    printf(GREEN("[===========] ") #a " " #comp " " #b);\
    printf(" %s\n", ((a) comp (b)) ? GREEN_HL("TRUE") : RED_HL("FALSE"));\
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
};

int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);

#endif
