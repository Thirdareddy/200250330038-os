#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int a ,b,sum;
sem_t s1,s2;
void *input_thread(void *data)
{
while(1)
{
sem_wait(&s1);
printf("T1:Getting new i/p's\n");
scanf("%d",&a);
scanf("%d",&b);
printf("T1:Got new i/p's\n");
sem_post(&s2);
}
}

void *processing_thread(void *data)
{
while(1)
{
sem_wait(&s2);
printf("T2:Starting processing\n");
sum=a+b;
printf("Sum:%d",sum);
sem_post(&s1);
}
}

int main()
{
sem_init(&s1,0,1);
sem_init(&s2,0,0);
pthread_t input_id,processing_id;
pthread_create(&input_id,NULL,input_thread,NULL);
pthread_create(&processing_id,NULL,processing_thread,NULL);
pthread_join(input_id,NULL);
pthread_join(processing_id,NULL);
}





