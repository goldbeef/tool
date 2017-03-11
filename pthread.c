/*************************************************************************
    > File Name: pthread.c
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年03月11日 星期六 21时40分21秒
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>

int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
        void *(*start_routine) (void *), void *arg) __attribute__ ((weak));

int main()
{
    if (pthread_create)
    {
        printf("multi-thread version\n");
    }
    else
    {
        printf("single-thread version\n");
    }
    return 0;
}
