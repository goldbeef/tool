/*************************************************************************
    > File Name: my_malloc_test.c
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年05月07日 星期日 16时18分57秒
 ************************************************************************/

#include <stdio.h>
#include "my_malloc.h"

int my_heap_init();
void* my_malloc(unsigned size);
void my_free(void* ptr);
void my_heap_show();

int main()
{
    int ret = my_heap_init();
    if (ret != 1)
    {
        printf("my_heap_init fail\n");
        return -1;
    }
    
    /*
    int size;
    while (scanf("%d", &size))
    {
        void* addr = my_malloc(size);
        if (addr == NULL)
        {
            printf("my_malloc error\n");
            continue;
        }
        printf("my_malloc succ, addr[%p], size[%d]\n", addr, size);
    }*/

    int i;
    void* addr[5];
    for (i = 0; i < 5; i++)
    {
        addr[i] = (char*) my_malloc(100);
        if (addr[i] == 0)
        {
            printf("my_malloc fail, index[%d]\n", i);
            continue;
        }
        printf("my_malloc succ, index[%d], ptr[%p]\n", i, addr[i]);
    }
    my_heap_show();
    printf("all malloc\n\n");
    for (i = 0; i < 5; i++)
    {
        printf("free, index[%d], ptr[%p]", i, addr[i]);
        my_free(addr[i]);
        my_heap_show();
    }
    printf("all free\n\n");
    
    my_heap_show();
    return 0;
}

