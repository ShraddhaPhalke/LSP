/*
	Program which create multiple threads and set its attributes accordingly.
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * th1_fun(void * p) 
{
	
	
	printf("Inside Thread1\n");
	printf("attr : %d",p);
	
	pthread_exit(NULL);
}


int main(int argc,char *argv[])
{

	pthread_t thread1;
	pthread_t thread2;
	int ret = 0;
	int s;
	pthread_attr_t attr;
	
	
	attr =open("demo.txt",O_RDONLY);
	s= pthread_attr_init(&attr);
	
	ret = pthread_create(&thread1,&attr,th1_fun,s);
	
	if(ret != 0) 
	{
		printf("unable to create thread\n");
	
	}
	
	
	
	pthread_join(thread1,NULL);
	

return 0;
}
