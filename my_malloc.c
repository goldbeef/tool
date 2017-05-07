/*************************************************************************
    > File Name: my_malloc.c
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年05月07日 星期日 15时10分08秒
 ************************************************************************/
#include <unistd.h>
#include <stdio.h>

//32 M
#define BLOCK_SIZE (32*1024*1024)

typedef struct _head_header
{
    enum{
        HEAP_BLOCK_FREE = 0xABABABAB,
        HEAP_BLOCK_USED = 0xCDCDCDCD,
    }type;

    unsigned size;

    struct _head_header* next;
    struct _head_header* prev;
}heap_header;

#define ADDR_ADD(a, o) ((char*)(a) + (o))
#define HEADER_SIZE (sizeof(heap_header))

static heap_header* list_head = NULL;

int my_heap_init()
{
    void* base = NULL;
    void* end = NULL;
    heap_header* header = NULL;
    
    int ret;
    base = (void*) sbrk(0);
    end  = (void*) ADDR_ADD(base, BLOCK_SIZE);
    ret =  brk(end);

    if (ret != 0)
        return -1;

    header = (heap_header*) base;
    header->size = BLOCK_SIZE;
    header->type = HEAP_BLOCK_FREE;
    header->next = NULL;
    header->prev = NULL;

    list_head = header;
    return 1;
}

void* my_malloc(unsigned size)
{
    heap_header* header;
    if (size == 0)
    {
        return NULL;
    }

    header = list_head;
    
    while (header != NULL)
    {
        if (header->type == HEAP_BLOCK_USED)
        {
            header = header->next;
            continue;
        }

        if (header->size >= size + HEADER_SIZE &&
            header->size <= size + HEADER_SIZE*2 )
        {
            header->type = HEAP_BLOCK_USED;
            return ADDR_ADD(header, HEADER_SIZE);
        }

        if (header->size > size + HEADER_SIZE*2)
        {
            //split
            heap_header* next = (heap_header*) ADDR_ADD(header, size + HEADER_SIZE);
            next->prev = header;
            next->next = header->next;
            next->type = HEAP_BLOCK_FREE;
            next->size = header->size - (size + HEADER_SIZE);

            header->next = next;
            header->size = size + HEADER_SIZE;
            header->type = HEAP_BLOCK_USED;
            return ADDR_ADD(header, HEADER_SIZE);
        }
        header = header->next;
    }
}

void my_free(void* ptr)
{
    if (ptr == NULL) return;

    heap_header* header = (heap_header*) ADDR_ADD(ptr, -HEADER_SIZE);
    if (header->type != HEAP_BLOCK_USED)
    {
        return ;
    }

    // ---|used|----
    header->type = HEAP_BLOCK_FREE;
    if (header->prev != NULL && header->prev->type == HEAP_BLOCK_FREE)
    {
        // merge with front block 
        header->prev->next = header->next;
        if (header->next != NULL)
            header->next->prev = header->prev;
        header->prev->size += header->size;
        
        header = header->prev;
    }

    if (header->next != NULL && header->next->type == HEAP_BLOCK_FREE)
    {
        // merge wtih back block 
        header->size += header->next->size;
        header->next = header->next->next;
        
        if (header->next != NULL)
        {
            header->next->prev = header;
        }
    }
}

void my_heap_show()
{
    heap_header* header = list_head;
    //dump
    int count = 0;
    printf("my_heap_show, baseAddr[%p], headerSize[%d]\n", header, HEADER_SIZE);
    while ( header != NULL)
    {
        if (header->type == HEAP_BLOCK_USED)
        {
            printf("blockIndex[%d], type[used], size[%d]\n", count, header->size);
        }
        else
        {
            printf("blockIndex[%d], type[free], size[%d]\n", count, header->size);
        }
        count++;
        header = header->next;
    }
}
