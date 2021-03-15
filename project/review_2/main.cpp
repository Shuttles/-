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
    EXPECT_EQ(add(5, 3), 9);
    EXPECT_EQ(add(6, 7), 13);
    EXPECT_EQ(add(6, 7), 14);
}

TEST(test, Funcadd) {
    EXPECT_EQ(add(5, 6), 11);
}

TEST(testFunc, add2) {
    EXPECT_EQ(add(1, 2), 3);
    EXPECT_EQ(add(1, 2), 4);
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(2, 3), 6);
}

TEST(testFunc, add3) {
    EXPECT_EQ(add(4, 5), 9);
    EXPECT_EQ(add(4, 6), 10);
}

int main(int argc, char *argv[]) {
    return RUN_ALL_TESTS();
}
