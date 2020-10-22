#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
int fd;
unsigned char rbuff[64];
fd=open("desd", O_RDONLY);
read(fd,rbuff,64);
printf("read received from sender:%s",rbuff);
close(fd);
}
