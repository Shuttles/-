

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

   `g++ -L ./lib -lgtest main.cpp  -I ./include/ -lpthread`

   + -lgtest相当于找`./lib`下的`libgtest.a`
   
2. 最新发现！！！(2021.1.7)

   我又一次尝试使用gtest时发现总是编译不成功(就用的上面的命令)，总是报错“未定义的使用”，找了一下午bug，最终发现是顺序问题！！！写成下面这样就对了！！

   `g++ -I ./include/ main.cpp -L ./lib/ -lgtest -lpthread`

   + 最终找到bug是因为这篇文章https://www.cnblogs.com/oloroso/p/4688426.html
   + 但是还是没懂 ==以前为什么就对 现在为什么就得这么写呢？==

## 断言

1. 什么是断言？

   + ASSERT
   + EXPECT 如果错了，不会结束程序运行

## 启示

1. 当我们在写一个工程时，一定要写makefile，它会让你的程序编译变得更简单！！





# 我的工程

## 1.第一阶段--初版

1. 经过判断可知，TEST和EXPECT_EQ是宏，RUN_ALL_TESTS是函数，然后开始编写宏和函数，先让他们通过编译

2. 通过编译之后发现，没有执行！这很正常，因为在main.cpp中，只是定义了测试函数，并没有调用！ 

3. 如何让TEST宏经过预处理之后的函数执行？

   + 一个办法是添加==属性==，让其先于主函数执行

     (但其实这种方法不是正规方法，因为从逻辑上是由主函数的`RUN_ALL_TESTS()`来执行TESTS宏的)
     
     具体实现就是在函数定义前一行写上`__attribute__((constructor))`

4. `RUN_ALL_TESTS()`如何知道程序中有多少测试用例？

   那一定是程序中存储了所有测试用例的信息，即用==函数指针数组==。

   ```c
   typedef void (*TestFuncT)()
   ```

   



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

1. 错误提示分为两部分，第二部分比较难，就是`"实际运算结果 VS 期待运算结果"`，前面所有为第一部分。

2. 第一部分

   直接printf输出即可

   ```c
   //在test.h中的EXPECT宏中
       if (_a cmp _b) haizei_test_info.success += 1;\
       else {\
           printf("\n");\
           printf(YELLOW_HL("\t%s:%d : Failure\n"), __FILE__, __LINE__);\
           printf(YELLOW_HL("\t\texpect " #a " " #cmp " " #b " actual: "));\
           printf("\n");\
       }\
   ```

3. 第二部分

   + 为啥不能用函数来实现？

     ==因为实际运算结果不一定是什么类型的呢！==

     所以要用宏

   + 而且要用泛型宏`_Generic`

   + 然而我照着光哥代码写还是报错。。目前还没搞懂原因，详情见test.h(34目录下的)
   
   + 离奇的是，我在mac上就能编译通过，在ubuntu上就不能通过，可能是底层编译器不同导致的？
   
   最终代码如下：
   
   ![img](https://wx2.sinaimg.cn/mw690/005LasY6gy1gmhpcm4z90j30nj0kygp9.jpg)
   
   





## 6.第六阶段--设计链表“外骨骼”

![img](https://wx2.sinaimg.cn/mw690/005LasY6gy1gmgnv4qy66j30m2091agc.jpg)

![img](https://wx4.sinaimg.cn/mw690/005LasY6gy1gmhoo6ae33j30op09pdn1.jpg)

![img](https://wx1.sinaimg.cn/mw690/005LasY6gy1gmhp9wngd4j30iw0hlacs.jpg)

1. 一个字--==骚==

2. 光哥说这种设计是一种非常==优美==的设计！一定要学会！

3. 链表node不存数据域！==只存指针域==！

   这样就可以放在不同类型的数据域中了！！

   即可以让任意类型拥有链表的结构！！通用性很强！

   具体结构如上图所示！

4. 而且，这样可以把==不同类型的node串成一串！！！==



## 遇到的bug

1. TEST宏展开的时候1、 2参数合并遇到重复定义

   + 在写TEST宏时，展开时在a##b之间加入一些特殊字符串即可

2. `haizei_test_info`被多次定义

   + 因为在main.cpp中引用了test.h，在test.cc中也引用了test.h，而`haizei_test_info`定义在test.h中，所以重复定义了。

   + 解决方法

     将`haizei_test_info`定义在==源文件==`test.cc`中，在头文件`test.h`中声明即可。
   
3. _Generic泛型宏在ubuntu上编译不通过，但是在mac中就编译成功了，难道是底层编译器不同导致的？