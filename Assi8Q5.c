/*
	Pogram which is used to increase the priority by 5.
*/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

int main()
{
	int ret=0;

	
	printf("Current priority is : %d\n",getpriority());
	
	ret = nice(5);
	
	printf("Changed priority is : %d\n",ret);
	

return 0;
}

