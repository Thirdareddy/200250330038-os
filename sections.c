#include<stdio.h>
#include<stdlib.h>
int a;//.bss
int b=5;//.data
int main()
{
int c;//stack
int *p=malloc(sizeof(int));//heap
}
