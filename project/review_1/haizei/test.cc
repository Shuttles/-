#include <haizei/test.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <haizei/linklist.h>

//int func_cnt = 0;
struct Function func_head, *func_tail = &func_head;//链表node
struct FunctionInfo haizei_test_info;//在源文件中定义，头文件中声明


int RUN_ALL_TESTS() {
    for (struct LinkNode *p = func_head.p.next; p != NULL; p = p->next) {
        struct Function *func = Head(p, struct Function, p); //取得首地址
        
        printf(GREEN("[====RUN====]") RED_HL(" %s\n"), func->str);
        haizei_test_info.total = haizei_test_info.success = 0;                 //清空数据
        func->func();                                                    //调用一组测试用例
        double rate_succ = 100.0 * haizei_test_info.success / haizei_test_info.total;
        printf(GREEN("[  "));

        if (fabs(rate_succ - 100.0) < 1e-6) {
            printf(BLUE_HL("%6.2lf%%"), rate_succ);
        } else {
            printf(RED_HL("%6.2lf%%"), rate_succ);
        }
        printf(
            GREEN("  ]")  " success : %d    total : %d"  "\n\n",
            haizei_test_info.success,
            haizei_test_info.total
        );
    }
    return 0;
}

void add_function(TestFuncT func, const char *str) {
    struct Function *temp = (struct Function *)calloc(1, sizeof(struct Function));
    temp->func = func;
    temp->str = strdup(str);
    func_tail->p.next = &(temp->p);
    func_tail = temp;
    return ;
}
