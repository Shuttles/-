/*************************************************************************
	> File Name: test.h
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年01月08日 星期五 11时29分01秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#include <haizei/linklist.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"


#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)

#define GREEN_HL(a) COLOR_HL(a, 32)
#define RED_HL(a) COLOR_HL(a, 31)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define YELLOW_HL(a) COLOR_HL(a, 33)

#define TEST(a, b) \
void a##_haizei_##b();\
__attribute__((constructor))\
void add##_haizei_##a##_haizei_##b() {\
    add_function(a##_haizei_##b, #a "." #b);\
}\
void a##_haizei_##b()

//必须要包装一下，因为展开不成字符串
#define TYPE_STR(a) _Generic((a), \
    int : "%d",\
    double : "%lf",\
    float : "%f",\
    long long : "%lld",\
    const char * : "%s"\
)

//用来包装TYPE_STR的
#define P(a, color) {\
    char frm[1000];\
    sprintf(frm, color("%s"), TYPE_STR(a));\
    printf(frm, a);\
}

#define EXPECT(a, b, comp) {\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    haizei_test_info.total += 1;\
    if (_a comp _b) {\
        haizei_test_info.success += 1;\
    } else {\
        printf("\n");\
        printf(YELLOW_HL("\t%s : %d : Failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpect :" #a " " #comp " " #b "; MyFunction: "));\
        P(_a, YELLOW_HL);\
        P(" vs Actual:", YELLOW_HL);\
        P(_b, YELLOW_HL);\
        printf("\n\n");\
    }\
    printf(GREEN("[-----------] ") #a " " #comp " " #b);\
    printf(" %s\n", (a) comp (b) ? GREEN_HL("TRUE") : RED_HL("FALSE"));\
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
    struct LinkNode p;//链表外骨骼  妙啊！
};


struct FunctionInfo {
    int total, success;  
};

extern struct FunctionInfo haizei_test_info;

/*
struct LinkNode {
    struct Function f;
    struct LinkNode *next;
};

struct LinkList {
    struct LinkNode head;
    struct LinkNode *tail;
    int n;
};*/

int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);



#endif
