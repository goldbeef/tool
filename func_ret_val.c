/*************************************************************************
    > File Name: func_ret_val.c
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年04月23日 星期日 15时55分51秒
 ************************************************************************/
typedef struct big_thing
{
    char buff[128];
}big_thing;

big_thing return_test()
{
    big_thing b;
    b.buff[0] = 0;
}

int main()
{
    big_thing n = return_test();
    return 0;
}

