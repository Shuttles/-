/*************************************************************************
	> File Name: main.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月15日 星期一 11时26分30秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <haizei/test.h>

int add(int a, int b) {
    return a + b;
}

TEST(testFunc, add) {
    EXPECT_EQ(add(5, 3), 8);
    EXPECT_NE(add(5, 3), 9);
    EXPECT_GT(add(6, 7), 10);
    EXPECT_LE(add(6, 7), 14);
    EXPECT_GT(add(6, 7), 20);
}

TEST(test1, Funcadd) {
    EXPECT_EQ(add(5, 6), 11);
}


int main(int argc, char *argv[]) {
    return RUN_ALL_TESTS();
}
