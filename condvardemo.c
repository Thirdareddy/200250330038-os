#include<stdio.h>
#include<pthread.h>
int flag=0;
pthread_mutex_t m1;
pthread_cond_t cv1;
void *thread_1(void *data)
{
printf("t1:grab mutex\n");
pthread_mutex_lock(&m1);
printf("t1:before busy loop\n");
while(flag!=1)
{
printf("t1:entering wait cond\n");
pthread_cond_wait(&cv1,&m1);
printf("exiting wait cond\n");
}
pthread_mutex_unlock(&m1);
printf("releasing mutex\n");
}
void *thread_2(void *data)
{
printf("t2:grab mutex\n");
pthread_mutex_lock(&m1);
flag=1;
pthread_mutex_unlock(&m1);
pthread_cond_signal(&cv1);
printf("t2:signalling\n");
}
int main()
{
pthread_t t1,t2;
pthread_mutex_init(&m1,NULL);
pthread_cond_init(&cv1,NULL);
pthread_create(&t1,NULL,thread_1,NULL);
pthread_create(&t2,NULL,thread_2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_mutex_destroy(&m1);
pthread_cond_destroy(&cv1);
}

