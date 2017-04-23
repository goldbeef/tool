/*************************************************************************
    > File Name: class_ret.cpp
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年04月23日 星期日 16时39分38秒
 ************************************************************************/

#include <iostream>
using namespace std;

struct cpp_obj
{
    cpp_obj()
    {
        cout << "ctor\n" << endl;
    }

    cpp_obj(const cpp_obj& c)
    {
        cout << "copy ctor\n" << endl;
    }

    cpp_obj& operator=(const cpp_obj& rhs)
    {
        cout << "operator=\n" << endl;
        return *this;
    }

    ~cpp_obj()
    {
        cout << "dtor\n" << endl;
    }
};

cpp_obj return_test()
{
    cpp_obj b;
    cout << "before return" << endl;
    return b;
}

int main()
{
    cpp_obj n;
    n = return_test();
    return 0;
}

