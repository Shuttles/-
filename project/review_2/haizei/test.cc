#include <haizei/test.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <haizei/linklist.h>

struct Function func_head, *func_tail = &func_head;
struct FunctionInfo haizei_test_info;

int RUN_ALL_TESTS() {
    for (struct LinkNode *p = func_head.p.next; p; p = p->next) {
        struct Function *run_func = NextHead(p, struct Function, p); 
        printf(GREEN("[====RUN====]") RED_HL(" %s\n"), run_func->str);
        haizei_test_info.total = haizei_test_info.success = 0;
        run_func->func();
        double rate = 100.0 * haizei_test_info.success / haizei_test_info.total;
        printf(GREEN("[  ") );
        if (fabs(rate - 100.0) < 1e-6) {
            printf(BLUE_HL("%6.2lf%%"), rate);
        } else {
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(GREEN("  ] "));
        printf(CYAN_HL("success : %d, total : %d\n"), haizei_test_info.success, haizei_test_info.total);

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
