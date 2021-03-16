#include <haizei/test.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <haizei/linklist.h>

int func_cnt = 0;
struct Function  func_head, *func_tail = &func_head;
struct TestInfo test_info;


int RUN_ALL_TESTS() {
    for (struct LinkNode *p = func_head.p.next; p; p = p->next) {
        struct Function *run_func = NextHead(p, struct Function, p);
        printf(GREEN("[====RUN====]") RED_HL(" %s\n"), run_func->str);
        test_info.total = test_info.success = 0;
        run_func->func();
        double rate = 100.0 * test_info.success / test_info.total;
        printf(GREEN("[  "));
        if (fabs(rate - 100.0) < 1e-6) {
            printf(GREEN_HL("%6.2lf%%"), rate);
        } else {
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(GREEN("  ] "));
        printf(CYAN_HL("success : %d, total : %d\n"), test_info.success, test_info.total);

        (p->next) && printf("\n");
    }
    return 0;
}

void add_function(TestFuncT func, const char *str) {
    struct Function *temp = (struct Function *)calloc(1, sizeof(Function));
    temp->func = func;
    temp->str = strdup(str);
    temp->p.next = NULL;
    func_tail->p.next = &(temp->p);
    func_tail = temp;

    func_cnt++;
    return ;
}
