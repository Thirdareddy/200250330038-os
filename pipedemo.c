#include<stdio.h>
#include <unistd.h>

int main()
{
pid_t id;
unsigned char rbuff[128];
int pfd[2];
pipe(pfd);
id=fork();
if(0==id)
{
read(pfd[0],rbuff,128);
printf("child received:%s\n",rbuff);
close(pfd[0]);
}
else
{
write(pfd[1],"cdac\n",5);
close(pfd[1]);
}
}
