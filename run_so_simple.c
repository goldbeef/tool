/*************************************************************************
    > File Name: run_so_simple.c
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年04月08日 星期六 21时05分10秒
 ************************************************************************/

#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char* argv[])
{
    void* handle;
    double (*func) (double);
    char* error;

    handle = dlopen(argv[1], RTLD_NOW);
    if (handle == NULL)
    {
        printf("dlopen error\n");
        return -1;
    }
    
    func = dlsym(handle, "sin");
    if ((error = dlerror()) != NULL)
    {
        printf("dlerror\n");
        return -1;
    }

    printf("result:[%f]\n", func(3.1415926/2));

    dlclose(handle);

    return 0;
}

