/*
	Program which creates new process which is responsible to write all the files names which are present on desktop in demo.txt file which should created newly.
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{

	int ret = 0;
	
	
	if((ret = fork()) == 0)
	{
		printf("Process  gets created\n ");
		execl("./filename",NULL,NULL);
	
	}
	else
	{
		
		printf("Parent is waiting \n");
		wait(NULL);

	}

return 0;
}
