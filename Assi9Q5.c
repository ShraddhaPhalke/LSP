/*
	Program which is used to get thread id inside its thread function.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * fun()
{
	pthread_t tid;
	
	tid = pthread_self();
	
	printf("Thread ID : %ld\n",tid);
	
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t thread;
	int ret = 0;
	
	printf("Inside main thread\n");
	
	ret = pthread_create(&thread,NULL,fun,NULL);
	
	if(ret != 0)
	{
	
		printf("Unable to create thread\n");
	}
	
	pthread_join(thread,NULL);
	
	printf("Terminating the main thread\n");

return 0;
}

