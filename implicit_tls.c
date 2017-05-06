/*************************************************************************
    > File Name: implicit_tls.c
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年05月06日 星期六 11时26分11秒
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>

#define LOOP 10000000

__thread int count = 0;
//int count = 0;

void * thread_routine(void* arg)
{
    for (int i = 0; i < LOOP; i++)
    {
        count++;
    }
    printf("thread[%lu], count[%d], end\n", pthread_self(), count);
}

int main()
{
    pthread_t thread[2];
    int ret, i;
    
    for (i = 0; i < 2; i++)
    {
        ret = pthread_create(&thread[i], NULL, thread_routine, NULL);
        if (ret != 0)
        {
            printf("pthread_create fail, index[%d], ret[%d]", i, ret);
            thread[i] = 0;
        }
    }

    for (i = 0; i < 2; i++)
    {
        if (thread[i] != 0)
            pthread_join(thread[i], NULL);
    }
    printf("main end\n");
    
    return 0;
}
