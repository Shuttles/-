# C语言第六章－－struct & Union

## 一、结构体

1. 结构类型在分配内存单元的时候，它会分配某一个大小的整数倍，而这某一个大小就叫做“对齐单元的大小”。

   一般情况下，对齐单元的大小结构类型中最大的==字段类型==所占的字节数。

   综上，结构体类型在定义成员时，成员的顺序会直接影响结构体变量所占内存的大小。

   for example

   ```c++
   struct node1 {
       char a;
       char b;
       int c;
   };
   
   struct node2 {
       char a;
       int c;
       char b;
   };
   
   //node1占8字节，　node2占12字节！！！
   ```


PS:struct 在C++里是个类，不是结构体变量的关键字！！！

## 二、共用体（联合体）

一句话：所有成员共用一段内存，其余的和结构体一样！！！！！

```c
 //如何将一个ＩＰ转换为一个int????
//为什么不可以直接输入到p变量的成员中？？？？？？？
#include <stdio.h>

union IP {
    int num;
    struct {
        unsigned char a1;
        unsigned char a2;:
        unsigned char a3;
        unsigned char a4;
    } ip;
} ;
int main() {
    union IP p; 
    int a[4];
    char str[100];
    while (~scanf("%s", str)) {
     		sscanf(str, "%d.%d.%d.%d", a, a + 1, a + 2, a + 3);   
        	p.ip.a1 = a[0];
        	p.ip.a2 = a[1];
        	p.ip.a3 = a[2];
        	p.ip.a4 = a[3];
        	printf("ip = %u\n",p.num);
    }
    return 0;
}
```

PS:

1. 在上面的代码中，输入192.168.0.1和192.168.0.2会发现它俩不相邻，这就牵扯到大小端操作系统的问题了

   ==小端操作系统：将低位存到低地址位中==

   ==大端操作系统：将低位存到高地址位中==

   而我的操作系统是小端的，而192.168.0.1和193.168.0.1是相邻的！！！！

   若想让它俩相邻，只需要反过来存即可。

2. 如果想写一个函数来判断机器是大端机还是小端机，该怎么写呢？

   ```C
   int is_little () {
       int x = 1;
       return ((char *)&x)[0];
   }
   ```

3. 主机字节序：就是主机是大端还是小端

   网络字节序：。。。