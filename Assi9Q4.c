/*
	Program which creates single thread and it accept one value from user and it return some value to the caller thread. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
void * fun()
{
	int value = 0;
	printf("Inside thread \n");
	printf("Enter value\n");
	scanf("%d",&value);
	
	printf(" Value from user: %d\n",value);
	return (void *) value;
}

int main(int argc, char *argv[])
{
	pthread_t thread;
	int ret = 0;
	void *res;
	
	printf("argv[1] : %s\n",argv[1]); 
	
	printf("Inside main thread\n");
	
	ret = pthread_create(&thread,NULL,fun,NULL);
	
	if(ret != 0)
	{
	
		printf("Unable to create thread\n");
	}
	
	pthread_join(thread,&res);
	
	printf("Thread returned %d\n",res);
	
	printf("Terminating the main thread\n");

return 0;
}
