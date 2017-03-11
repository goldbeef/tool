/*************************************************************************
    > File Name: manul_name_nagling.cpp
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年03月11日 星期六 16时45分51秒
 ************************************************************************/

#include <stdio.h>

namespace myname
{
    int var = 42;
}

extern "C" double _ZN6myname3varE;
//extern double _ZN6myname3varE;

int main()
{
    printf("%d\n", _ZN6myname3varE);
    return 0;
}
