/*
	Program which create 4 number of threads and our main thread waits till all the thread terminates.
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


void * th1_fun() 
{
	

	printf("Inside Thread1\n");
	
	pthread_exit(NULL);
}

void * th2_fun() 
{
	
	printf("Inside Thread2\n");
	
	pthread_exit(NULL);
}
void * th3_fun() 
{
	
	printf("Inside Thread3\n");
	
	pthread_exit(NULL);
}
void * th4_fun() 
{
	
	printf("Inside Thread4\n");
	
	pthread_exit(NULL);
}

int main(int argc,char *argv[]) // main thread
{
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	pthread_t thread4;
	
	int ret =0;
	
	printf("inside main thread\n");
	
	ret = pthread_create(&thread1,NULL,th1_fun,NULL);
	
	if(ret != 0) 
	{
		printf("unable to create thread\n");
	
	}
	pthread_join(thread1,NULL);
	
	ret = pthread_create(&thread2,NULL,th2_fun,NULL);
	if(ret != 0)  
	{
		printf("unable to create thread\n");
	
	}
	pthread_join(thread2,NULL);
	
	ret = pthread_create(&thread3,NULL,th3_fun,NULL);
	if(ret != 0)  
	{
		printf("unable to create thread\n");
	
	}
	pthread_join(thread3,NULL);
	
	ret = pthread_create(&thread4,NULL,th4_fun,NULL);
	if(ret != 0)  
	{
		printf("unable to create thread\n");
	
	}
	pthread_join(thread4,NULL);
	
	
	printf("terminating the main thread\n");
	

return 0;
}
