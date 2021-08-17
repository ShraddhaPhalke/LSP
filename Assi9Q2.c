/*
	Program which creates two thread,first thread print numbers from 1 to 500 and other print numbersd from 500 to 1
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


void * fun() //Thread1
{

	int i=0;
	
	printf("Inside first thread \n");
	
	for(i=1;i<=500;i++)
	{
		printf("Thread1 : %d\n",i);
	}	
	pthread_exit(NULL);
}

void * gun() //Thread2
{
	int i=0;
	printf("Inside second thread \n");
	for(i=500;i>=1;i--)
	{
		printf("Thread2 : %d\n",i);
	}	
	pthread_exit(NULL);
}

int main(int argc,char *argv[]) // main thread
{
	pthread_t thread1;
	pthread_t thread2;
	
	int ret =0;
	
	
	printf("inside main thread\n");
	
	ret = pthread_create(&thread1,NULL,fun,NULL);
	
	if(ret != 0)  
	{
		printf("unable to create thread\n");
	
	}
	pthread_join(thread1,NULL);
	
	
	ret = pthread_create(&thread2,NULL,gun,NULL);
	
	if(ret != 0)  
	{
		printf("unable to create thread\n");
	
	}
	
	pthread_join(thread2,NULL);
	
	
	printf("terminating the main thread\n");
	

return 0;
}
