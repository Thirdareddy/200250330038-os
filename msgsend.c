#include<stdio.h>
#include <mqueue.h>
#include <fcntl.h>           
#include <sys/stat.h>        
#include <mqueue.h>
#include<stdio.h>

int main()
{
mqd_t mqfd;
struct mq_attr cdacmq_attr;
cdacmq_attr.mq_flags=0;
cdacmq_attr.mq_maxmsg=4;
cdacmq_attr.mq_msgsize=128;
cdacmq_attr.mq_curmsgs=0;
mqfd=mq_open("/cdacmq",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR,&cdacmq_attr);
mq_send(mqfd,"hello\n",5,0);
mq_close(mqfd);
}


