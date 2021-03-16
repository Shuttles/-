/*************************************************************************
	> File Name: linklist.h
	> Author: 少年宇
	> Mail: 
	> Created Time: 2021年03月16日 星期二 20时17分47秒
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H

#define offset(T, name) (long long)(&(((T *)(0))->name))

#define NextHead(p, T, name) ((T *)(((char *)(p)) - offset(T, name)))


struct LinkNode {
    struct LinkNode *next;
};

#endif
