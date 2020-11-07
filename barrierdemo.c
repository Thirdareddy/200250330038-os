#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_barrier_t barr;
void *s1(void *arg)
{
printf("started initialization\n");
sleep(2);
printf("s1:initialized\n");
pthread_barrier_wait(&barr);
printf("s1:started\n");
}
void *s2(void *arg)
{
printf("started initialization\n");
sleep(12);
printf("s2:initialized\n");
pthread_barrier_wait(&barr);
printf("s2:started\n");
}
void *s3(void *arg)
{
printf("started initialization\n");
sleep(5);
printf("s3:initialized\n");
pthread_barrier_wait(&barr);
printf("s3:started\n");
}
void *s4(void *arg)
{
printf("started initialization\n");
sleep(3);
printf("s4:initialized\n");
pthread_barrier_wait(&barr);
printf("s4:started\n");
}

int main()
{
pthread_t s,e,l,a;
pthread_barrier_init(&barr,NULL,4);
pthread_create(&s,NULL,s1,NULL);
pthread_create(&e,NULL,s2,NULL);
pthread_create(&l,NULL,s3,NULL);
pthread_create(&a,NULL,s4,NULL);
pthread_join(s,NULL);
pthread_join(e,NULL);
pthread_join(l,NULL);
pthread_join(a,NULL);
pthread_barrier_destroy(&barr);
}
