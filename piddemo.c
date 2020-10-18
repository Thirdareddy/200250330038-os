#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
pid_t id;
pid_t parentid;
id=getpid();
parentid=getppid();
printf("PID:%d\n",id);
printf("PPID:%d",parentid);
}
