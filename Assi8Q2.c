/*
	Program which create two processess.
	Process 1 count number of capital chracters from demo.txt and Process 2 count no of capital character from hello.txt. Both the 		processesess write its count in count.txt file.
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{

	int ret = 0;
	int ret1 = 0;
	int fd = 0;
	fd= open("count.txt",O_WRONLY);
	
	if((ret = fork()) == 0)
	{
		printf("Process 1 gets created\n ");
		execl("./capital1","demo1.txt","count.txt",NULL);
	
	}
	else
	{
		
			printf("Process 2 gets created\n ");
			execl("./capital2","hello.txt","count.txt",NULL);

	}

return 0;
}
