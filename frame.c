/*************************************************************************
    > File Name: frame.c
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年04月22日 星期六 15时53分42秒
 ************************************************************************/

#include <stdio.h>

int add(int x, int y)
{
    return x + y;
}

int foo(int n)
{
    int val = add(n, n);
    return val;
}

int main()
{
    int key = 5;
    return foo(key);
}
