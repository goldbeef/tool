#include <stdio.h>

int global_init_val = 84;
int global_uninit_val;

__attribute__((section("foo"))) int global = 42;

void func1(int i)
{
    printf("%d\n", i);
}

int main(void)
{
    static int static_init_val = 30;
    static int static_uninit_val;

    int a  = 1;
    int b;
    func1(static_init_val + static_uninit_val + a + b);
    return a;
}
