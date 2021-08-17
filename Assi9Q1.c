/*
	Program which is used to create simple thread by using pthread library
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * fun()
{

	printf("Inside thread \n");
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t thread;
	int ret = 0;
	int no = 10;
	
	
	printf("Inside main thread\n");
	
	ret = pthread_create(&thread,NULL,fun,(void *)no);
	
	if(ret != 0)
	{
	
		printf("Unable to create thread\n");
	}
	
	pthread_join(thread,NULL);
	
	printf("Terminating the main thread\n");

return 0;
}
