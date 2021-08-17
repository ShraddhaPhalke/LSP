/*
	Program which is used to write priority of process
*/
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

int main()
{
	
	printf("Priority of current process is : %d\n",getpriority());
	
	return 0;
}

