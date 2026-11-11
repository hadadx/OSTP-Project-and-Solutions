#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "reverse.h"

int main(int argc, char const *argv[])
{
    if (argc < 2){errorHandle(NO_INPUT_FILE);exit(1);}
    if (argc > 3){errorHandle(TO_MANY_ARGC);exit(1);}

    FILE *src = fopen(argv[1], "rb");
    FILE *des = fopen(argv[2], "wb");

    if (src == NULL || des == NULL){errorHandle(NO_INPUT_FILE);exit(1);}

    if (fseek(src, 0, SEEK_END) != 0){errorHandle(SEEK_FAIL);exit(1);}

    unsigned long size = ftell(src);
    char *fileBuff = malloc(size);
    if (fileBuff == NULL){errorHandle(MALLOC_ERROR); exit(1);}


    fseek(src, 0, SEEK_SET);
    unsigned long i = 0;

    for (i = 0; i < size; i++)
    {
        char ch = fgetc(src);
        fileBuff[i] = ch;
    }
    fileBuff[i] = 0;

    size_t diff = 0;
    char ch;
    while (i > 0)
    {
        ch = fileBuff[--i];

        switch (ch)
        {
        case '\n':
            if (diff > 0)
            {
                fwrite(&fileBuff[i + 1], 1, diff, des);
            }

            putc('\n', des);
            diff = 0;
            break;

        case ' ':
            if (diff > 0)
            {
                fwrite(&fileBuff[i + 1], 1, diff, des);
            }

            putc(' ', des);
            diff = 0;
            break;

        case '\t':
            if (diff > 0)
            {
                fwrite(&fileBuff[i + 1], 1, diff, des);
            }

            putc('\t', des);
            diff = 0;
            break;

        default:
            diff++;
            break;
        }
    }

    if (diff > 0)
    {
        fwrite(&fileBuff[0], 1, diff, des);
    }



    return 0;
}
