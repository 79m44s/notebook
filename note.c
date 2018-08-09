#include<stdio.h>
#include<string.h>
#include<fcntl.h>

#define FLAG O_CREAT | O_RDWR 

#define MODE S_IRWXU | S_IWOTH| S_IXOTH | S_IROTH

int createFile()
{
    int fd;
    char path[100];
    scanf("%s",path);
    
    if((fd=open(path,FLAG,MODE))==-1)
    {
        return 0;
    }

    printf("fd = %d\n",fd);
    
    return fd;
}

/**
函数名称：

**/
size_t writeFile(int fd)
{
    size_t wt;
    char str[4096];
    int i;
    for(i=0;i<4096;i++)
    {
        str[i]=getchar();
        if(27==str[i])
        {
            break;
        }
    }
   // printf("%s\n",str);
    wt=write(fd,str,strlen(str));
    close(fd);
    return wt;

 }
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
    
   // printf("文件打开成功，请输入：");
   // writeFile(fd);
    return 0;
}
