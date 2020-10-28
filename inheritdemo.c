#include<stdio.h>
#include<unistd.h>

int main()
{
pid_t id;
id=fork();
if(0==id)
{
printf("child starting\n");
sleep(12);
printf("exiting child\n");
}
else
{
printf("parent starting\n");
sleep(2);
printf("exiting parent\n");
}
}
