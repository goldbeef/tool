/*************************************************************************
    > File Name: weak_ref.c
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年03月11日 星期六 21时26分35秒
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>

void foo() __attribute__ ((weak));
//void foo();

int main()
{
    if (foo)
    {
        printf("foo is define\n");
    }
    else
    {
        printf("foo is not define\n");
    }
    return 0;
}
