#include<stdio.h>
#include"note.h"
int main()
{
    int fd;
    size_t wt;
    if((fd=createFile())== 0)
    {
        printf("打开文件出错！\n");
        return 0;
    }

    if((wt=writeFile(fd))==-1)
    {
        printf("写入文件出错！\n");
        return 0; 
    }

    return 0;
}
