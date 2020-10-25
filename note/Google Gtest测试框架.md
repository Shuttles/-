

# 项目背景

1. 声明放在头文件中，定义放在源文件中(否则会发生重定义)

2. 测试框架是跟着语言走的。

3. 什么是单元测试？
   
   + 单元测试(unit testing)，是指对软件中的最小可测试单元进行检查和验证，比如C语言中单元指一个函数，java中单元指一个类
   
4. Gtest可以干什么？

5. makfile是干啥的

   是linux/Unix中编译程序的工具

6. 但是电脑的环境不一样，makefile就可能不一样

   这时候，cmake就派上用场了

   有了cmake，就不用写makefile了，为什么呢

   cmake就根据你本机的环境，生成适合你本机环境的makefile文件

7. 有了makefile之后，如何编译呢？

   make

   只要上面一行命令即可！



## 静/动态链接库

1. 一组对象文件(.c 放的是==定义==)的打包就是静态/动态链接库
2. 一个第三方模块库给我们的程序提供功能的时候最明智的选择就是提供**<u>*静态链接库和头文件</u>***
3. 一般情况下静态链接库(.a)会生成在`.lib`目录下，头文件(.h)生成在`include`目录下



### g++添加静态链接库路径

`-L`



## 使用gtest

1. 编译命令

   `g++ -L ./lib main.cpp -lgtest -I ./include/ -lpthread`

   + -lgtest相当于找`./lib`下的`libgtest.a`





## 断言

1. 什么是断言？

   断言就是错了就直接退出程序

## 启示

1. 当我们在写一个工程时，一定要写makefile，它会让你的程序编译变得更简单！！





# 我的工程

## 1.第一阶段

1. 如何让TEST宏执行？

   + 一个办法是添加属性，让其先于主函数执行

     (但其实这种方法不是正规方法，因为从逻辑上是由主函数的`RUN_ALL_TESTS()`来执行TESTS宏的)

2. `RUN_ALL_TESTS()`如何知道程序中有多少测试用例？

   那一定是程序中存储了所有测试用例的信息，即用==函数指针数组==。



## 2.第二阶段--输出彩色提示符

其实封装一组宏就行

```c++
//在test.h中
#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"

#define GREEN(a) COLOR(a, 32)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)
#define RED(a) COLOR(a, 31)

#define GREEN_HL(a) COLOR_HL(a, 32)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define YELLOW_HL(a) COLOR_HL(a, 33)
#define RED_HL(a) COLOR_HL(a, 31)
```



## 3.第三阶段--修改断言输出

```c
//在test.h中
#define EXPECT(a, b, cmp) {\
    printf(GREEN("[-----------]") #a " " #cmp " " #b);\
    printf(" %s\n", (a)  cmp  (b) ? GREEN_HL("TRUE") : RED_HL("FALSE"));\
}

#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)
```



## 4.第四阶段--尾部输出每组测试用例成功率

1. 在==头文件==`test.h`中定义一种结构体类型，来存储测试用例成功与否的信息。

2. 在==源文件==`test.cc`中定义上述结构体类型的变量，在`test.h`中==外部声明==这个变量(==否则会造成重复定义==)

3. 在`test.h`中

   ```c
   #define EXPECT(a, b, cmp) {\
       __typeof(a) _a = (a), _b = (b);\        //这样是为了防止多次计算，因为a可能是var++什么的
       haizei_test_info.total += 1;\
       if (_a cmp _b) haizei_test_info.success += 1;\
       printf(GREEN("[-----------]") " " #a " " #cmp " " #b);\
       printf(" %s\n", (_a)  cmp  (_b) ? GREEN_HL("TRUE") : RED_HL("FALSE"));\
   }
   ```

   

4. 接着在`RUN_ALL_TESTS()`函数中输出信息

   ```c
           double rate =  100.0 * haizei_test_info.success / haizei_test_info.total;
           printf(GREEN("[  "));
           if (fabs(rate - 100.0) < 1e-6) {  //浮点数无法精确比较是否相等
               printf(BLUE_HL("%6.2lf%%"), rate);
           } else {
               printf(RED_HL("%6.2lf%%"), rate);
           }
           printf(
               GREEN("  ]") 
               " success : %d      total : %d\n\n",
               haizei_test_info.success,
               haizei_test_info.total
           );
   ```

   

## 5.第五阶段--输出错误提示





## 6.第六阶段--设计链表“外骨骼”

1. 一个字--==骚==
2. 光哥说这种设计是一种非常==优美==的设计！一定要学会！

### 遇到的bug

1. TEST宏展开的时候1、 2参数合并遇到重复定义

   + 在写TEST宏时，展开时在a##b之间加入一些特殊字符串即可

2. `haizei_test_info`被多次定义

   + 因为在main.cpp中引用了test.h，在test.cc中也引用了test.h，而`haizei_test_info`定义在test.h中，所以重复定义了。

   + 解决方法

     将`haizei_test_info`定义在==源文件==`test.cc`中，在头文件`test.h`中声明即可。