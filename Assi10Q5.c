/* 
	Program which create two threads by using pthread API , where one thread count number of capital characters from demo.txt file and another thread count number of small characters from the same file.
*/

 /* 
	Program which create two threads by using pthread API , where one thread count number of capital characters from demo.txt file and another thread count number of small characters from the same file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
 
void * fun_capital(void * p)
{
	char ch;
	int count=0;
	int ret = 0;
	int fd = 0;
	
	while((ret = read(p,&ch,sizeof(ch))) != 0)
 	{
 		if((ch >= 'A')&&(ch <= 'Z'))
 		{
 			count++;
 		}
 	}
 	if(ret == -1)
 	{
 		printf("unable to read");
 	}
 	printf("Number of capital characters are : %d\n",count);
 	lseek(p,0,SEEK_SET);		
	return NULL;

}

void * fun_small(void * p)
{
	char ch;
	int count=0;
	int ret =0;
	int fd = 0;
	
	while((ret = read(p,&ch,sizeof(ch))) != 0)
 	{
 		if((ch >= 'a')&&(ch <= 'z'))
 		{
 			count++;
 		}
 	}
 	if(ret == -1)
 	{
 		printf("unable to read");
 	}
 	printf("Number of small characters are : %d\n",count);		
	return NULL;

}


int main(int argc,char *argv[])
{
	pthread_t thread1;
	pthread_t thread2;
	int ret = 0;
	int fd = 0;
	int *ret1 ;
	
	fd =open("demo.txt",O_RDONLY);
	
	ret=(int *)malloc(sizeof(int));
	ret1 = fd;
	
	ret = pthread_create(&thread1,NULL,fun_capital,ret1);
	
	if(ret != 0) 
	{
		printf("unable to create thread\n");
	
	}
	
	pthread_join(thread1,NULL);
	
	ret = pthread_create(&thread2,NULL,fun_small,ret1);
	
	if(ret != 0) 
	{
		printf("unable to create thread\n");
	
	}
	
	pthread_join(thread2,NULL);

return 0;
}
