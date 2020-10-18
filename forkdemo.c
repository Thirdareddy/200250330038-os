#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
pid_t id;
printf("Before fork\n");
id=fork();
printf("After fork id=%d pid=%d ppid=%d\n",id,getpid(),getppid());
}
