#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<curses.h>
#define FLAG O_CREAT | O_RDWR 

#define MODE S_IRWXU | S_IWOTH| S_IXOTH | S_IROTH

//#define ESC "\033"
#define UP "\033[A"
#define DOWN "\033[B"
#define RIGHT "\033[C"
#define LEFT "\033[D"

#define ESC 27
/*#define UP 72
#define DOWN 80
#define RIGHT 75
#define LEFT 77*/
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

size_t writeFile(int fd)
{
    size_t wt;
    char str[4096];
    int i;
    for(i=0;i<4096;i++)
    {
        str[i]=getchar();
        if(ESC==str[i])
        {
            break;
        }
		
		if(!strcmp(str[i], UP))
		{
			printf("这是上键");
			i--;
		}
		/*if(UP==str[i])
		{
			printf("\033[?25h");
			i--;
		}*/
		/*if('s'==str[i])
		{
			printf("\033[1B");			
			str[i]='\n';
		}
		if('a'==str[i])
		{
			printf("\033[1D");
			
		}*/
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
