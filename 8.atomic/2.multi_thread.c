#include <stdio.h>
#include <stdatomic.h>
#include <pthread.h>

#define THREAD_NUM 10

atomic_int counter = ATOMIC_VAR_INIT(0);
int cntr = 0;

void *calc(void *arg)
{
    for (int i = 0; i < 1000; i++)
    {
        atomic_fetch_add_explicit(&counter, 1, memory_order_relaxed);
        ++cntr;
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[THREAD_NUM];

    for (int i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_create(&threads[i], NULL, calc, NULL) != 0)
        {
            perror("Failed to create thread");
            return -1;
        }
    }

    for (int i = 0; i < THREAD_NUM; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Atomic counter = %d\n", atomic_load_explicit(&counter, memory_order_relaxed));
    printf("Non-atomic counter = %d\n", cntr);
    return 0;
}