/*************************************************************************
    > File Name: variable_param_sum.c
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年05月06日 星期六 09时56分44秒
 ************************************************************************/

#include <stdio.h>

#define LOG_DEBUT(args...) fprintf(stdout, ##args)

int sum(int num, ...)
{
    int *ptr = &num + 1;
    int i, sum;
    sum = 0;
    for (i = 0; i < num; i++)
    {
        sum += ptr[i];
    }
    return sum;
}

int main()
{
    printf("sum[1,2,3] = %d\n", sum(3, 1, 2, 3));
    LOG_DEBUT("LOG_DEBUT, var[%d], msg[%s]\n", 1, "hello");
    return 0;
}
