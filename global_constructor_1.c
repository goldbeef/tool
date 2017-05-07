/*************************************************************************
    > File Name: global_constructor.c
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年05月07日 星期日 09时56分22秒
 ************************************************************************/

#include <stdio.h>

void my_init(void)
{
    printf("hello ");
}

typedef void (*ctor_t) (void);

ctor_t __attribute__((section (".ctors"))) my_init_init_p = &my_init;

int main()
{
    printf("world\n");
    return 0;
}
