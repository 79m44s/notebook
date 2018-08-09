#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include"note.h"

//open函数标志位，若不存在指定文件则创建该文件，并以可读写方式打开
#define FLAG O_CREAT | O_RDWR  

//创建文件的权限，用户和其他用户均可读、写、执行
#define MODE S_IRWXU | S_IWOTH| S_IXOTH | S_IROTH


/************************************
函数名称：createFile
描述：根据用户输入打开或创建文件
输入：无
返回值：int fd--文件描述符
*************************************/
int createFile()
{
    int fd;
    char pathname[100];
    scanf("%s",pathname);
    
    if((fd=open(pathname,FLAG,MODE))==-1)
    {
        return 0;
    }

   // printf("fd = %d\n",fd);
    printf("请输入内容:\n");
    return fd;
}

/************************************
函数名称：writeFile
描述：将键盘输入写进指定文件
输入：int fd--指定文件的函数描述符
返回值：size_t wt--返回实际写入字节数，出错时返回-1
*************************************/
size_t writeFile(int fd)
{
    size_t wt;
    char str[4096];
    int i;
    for(i=0;i<4096;i++)
    {
        str[i]=getchar();
        //scanf("%s",str);
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
