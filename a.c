/*************************************************************************
    > File Name: a.c
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年03月19日 星期日 22时03分42秒
 ************************************************************************/
extern int shared;

int main()
{
    int a = 100;
    swap(&a, &shared);
    return 0;
}

