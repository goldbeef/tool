/*************************************************************************
    > File Name: memeory.c
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年05月07日 星期日 15时14分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 1024;
    char* ptr = (char*)malloc(size);
    if (ptr == NULL)
    {
        printf("malloc fail\n");
        return -1;
    }
    printf("malloc succ, ptr[%p]\n", ptr);
    return 0;
}
