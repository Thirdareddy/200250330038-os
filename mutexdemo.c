#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
//pthread_mutexattr_t count_mutex_attr;
pthread_mutex_t count_mutex;
int count=0;

void *inc_thread(void *arg)
{
while(1)
{
pthread_mutex_lock(&count_mutex);
count++;
printf("inc %d",count);
pthread_mutex_unlock(&count_mutex);
}
}
void *dec_thread(void *arg)
{
while(1)
{
pthread_mutex_lock(&count_mutex);
count--;
printf("dec %d",count);
pthread_mutex_unlock(&count_mutex);
}
}

int main()
{
pthread_t tid_inc,tid_dec;
pthread_mutex_init(&count_mutex,NULL);
//pthread_mutex_init(&count_mutex_attr,NULL);
pthread_create(&tid_inc,NULL,inc_thread,NULL);
pthread_create(&tid_dec,NULL,dec_thread,NULL);
pthread_join(tid_inc,NULL);
pthread_join(tid_dec,NULL);
pthread_mutex_destroy(&count_mutex);
//pthread_mutex_destroy(&count_mutex_attr);
}
