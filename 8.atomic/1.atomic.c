#include <stdio.h>
#include <stdatomic.h>

atomic_ullong num = ATOMIC_VAR_INIT(0);

int main()
{
    printf("Before : %llu\n", atomic_load(&num));
    atomic_fetch_add(&num, 1);
    printf("After : %llu\n", atomic_load(&num));
    return 0;
}