/*************************************************************************
	> File Name: test.h
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月15日 星期一 15时44分38秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"

#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define YELLOW(a) COLOR(a, 33)
#define BLUE(a) COLOR(a, 34)
#define PURPLE(a) COLOR(a, 35)
#define CYAN(a) COLOR(a, 36)

#define GREEN_HL(a) COLOR_HL(a, 32)
#define RED_HL(a) COLOR_HL(a, 31)
#define YELLOW_HL(a) COLOR_HL(a, 33)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define PURPLE_HL(a) COLOR_HL(a, 35)
#define CYAN_HL(a) COLOR_HL(a, 36)


#define TEST(a, b) \
void a##_haizei_##b();\
__attribute__((constructor))\
void add##_haizei_##a##_haizei_##b() {\
    add_function(a##_haizei_##b, #a "." #b);\
}\
void a##_haizei_##b()


//然而在ubuntu上总是报错，mac上却不报错
#define TYPE_STR(a) _Generic((a),\
    int : "%d",\
    double : "%lf",\
    float : "%f",\
    long long : "%lld",\
    const char * : "\s"\
)

#define P(a, color) {\
    char frm[1000];\
    sprintf(frm, color("%s"), TYPE_STR(a));\
    printf(frm, a);\
}


#define EXPECT(a, b, comp) {\
    printf(GREEN("[-----------] ") #a " " #comp " " #b);\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    printf(" %s\n", ((_a) comp (_b)) ? GREEN_HL("TRUE") : RED_HL("FALSE"));\
    haizei_test_info.total += 1;\
    if (_a comp _b) haizei_test_info.success += 1;\
    else {\
        printf("\n");\
        printf(YELLOW_HL("\t%s : %d: Failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpect: " #a " " #comp " " #b));\
        printf(YELLOW_HL(" actual: ") "\n");\
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
};

struct FunctionInfo {
    int total, success;
};

extern struct FunctionInfo haizei_test_info;

int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);



#endif
