#include<stdio.h>
#include <mqueue.h>
#include <fcntl.h>           
#include <sys/stat.h>        
#include <mqueue.h>
#include<stdio.h>

int main()
{
mqd_t mqfd;
int prio;
char buff[128];
struct mq_attr cdacmq_attr;
cdacmq_attr.mq_flags=0;
cdacmq_attr.mq_maxmsg=4;
cdacmq_attr.mq_msgsize=128;
cdacmq_attr.mq_curmsgs=0;
mqfd=mq_open("/cdacmq",O_RDONLY|O_CREAT,S_IRUSR|S_IWUSR,&cdacmq_attr);
mq_receive(mqfd,buff,128,&prio);
printf("received %s\n",buff);
mq_close(mqfd);
}

