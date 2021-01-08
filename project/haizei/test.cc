#include <haizei/test.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int func_cnt = 0;
Function func_arr[100];
struct FunctionInfo haizei_test_info;//在源文件中定义，头文件中声明


int RUN_ALL_TESTS() {
    for (int i = 0; i < func_cnt; i++) {
        printf(GREEN("[====RUN====]") RED_HL(" %s\n"), func_arr[i].str);
        haizei_test_info.total = haizei_test_info.success = 0;                 //清空数据
        func_arr[i].func();                                                    //调用一组测试用例
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
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].str = strdup(str);
    func_cnt++;
    return ;
}
