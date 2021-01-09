/*************************************************************************
	> File Name: linklist.h
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年01月08日 星期五 22时26分32秒
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H

//返回T类型中name域的偏移量
#define offset(T, name) (long long)(&(((T *)(0))->name))

//根据当前node的地址，去获取到下一个node的首地址
//p是下一个node的地址
//T是下一个node的数据类型
//name是指针域的名字
//返回的是T*类型的首地址
#define Head(p, T, name)  ((T *)(((char *)p) - (char *)offset(T, name)))

//链表外骨骼 妙啊！
//可以存放在数据域不同的struct里！通用性很强！
struct LinkNode {
    struct LinkNode *next;
};



#endif
