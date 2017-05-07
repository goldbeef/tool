/*************************************************************************
    > File Name: my_malloc.h
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年05月07日 星期日 16时07分19秒
 ************************************************************************/

int my_heap_init();
void* my_malloc(unsigned size);
void my_free(void* ptr);
void my_heap_show();
