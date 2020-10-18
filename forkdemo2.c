#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
pid_t id;
id=fork();
if(0==id)
{
printf("child  pid=%d,ppid=%d",getpid(),getppid());
}
else
{
printf("parent  pid=%d,ppid=%d",getpid(),getppid());
}
}
