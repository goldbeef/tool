/*************************************************************************
    > File Name: target.c
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年03月29日 星期三 22时18分12秒
 ************************************************************************/

#include <stdio.h>
#include <bfd.h>

int main()
{
    const char** t = bfd_target_list();
    while(*t)
    {
        printf("%s\n", *t);
        t++;
    }
    return 0;
}
