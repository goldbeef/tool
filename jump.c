/*************************************************************************
    > File Name: jump.c
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年05月06日 星期六 10时26分15秒
 ************************************************************************/

#include <stdio.h>
#include <setjmp.h>

jmp_buf b;

void f()
{
    longjmp(b, 1);
}

int main()
{
    if (setjmp(b))
    {
        printf("world!");
    }
    else
    {
        printf("hello");
        f();
    }
    return 0;
}
