#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
int fd;
char a='c';
fd=fopen("cdesd.txt",O_WRONLY | O_CREAT);
fprintf(fd,"%c",a);
fclose(fd);
}
