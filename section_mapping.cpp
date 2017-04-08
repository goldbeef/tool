#include <stdlib.h>
#include <unistd.h>

 
int main(int argc, char* argv[])
{
    char stackBuff[1024*1024];
    char *heapBuff = (char*) malloc(1024*1024);

    while(1)
    {
        sleep(1000);
    }
    return 0;
}
