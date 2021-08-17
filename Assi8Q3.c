/*
	Program which creates one process which accept one directory name.That process will rename all names of regular files with sequential number.(1.txt,2.txt etc).
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
		execl("./renamefile",argv[1],NULL);
	
	}
	else
	{
		printf("Parent process is running\n");
			
	}

return 0;
}
