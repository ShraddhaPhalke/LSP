/*
	Program which creates single thread and we have to pass parameter to that thread from main thread
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * fun(void *p)
{
	
	printf("Inside thread \n");
	printf("Parameter : %d\n",p);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t thread;
	int ret = 0;
	int arg = 10;
	
	
	printf("Inside main thread\n");
	
	ret = pthread_create(&thread,NULL,fun,(void *)arg);
	
	if(ret != 0)
	{
	
		printf("Unable to create thread\n");
	}
	
	pthread_join(thread,NULL);
	
	printf("Terminating the main thread\n");

return 0;
}
