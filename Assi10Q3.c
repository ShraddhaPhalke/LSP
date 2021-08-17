/*
	Program which is uswd to predict the problem due to lack of synchronization.
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

static int global = 0;

static void * threadfun(void * arg)
{
	int limit = *((int *)arg);
	int local = 0;
	int i =0;
	
	for(i=0;i<limit;i++)
	{
	
		local = global;
		local++;
		global = local;
	}
	return NULL;	
}

int main(int argc,char *argv[])
{

	pthread_t thread1;
	pthread_t thread2;
	int ret = 0;
	int no = 10000000;
	
	ret = pthread_create(&thread1,NULL,threadfun,&no);
	
	if(ret != 0) 
	{
		printf("unable to create thread\n");
	
	}
	
	ret = pthread_create(&thread2,NULL,threadfun,&no);
	
	if(ret != 0) 
	{
		printf("unable to create thread\n");
	
	}
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	printf("Global value : %d\n",global);
return 0;
}
