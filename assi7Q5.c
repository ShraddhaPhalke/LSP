/*	
	Program which is used to create deamon process.
*/	

#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/fs.h>
int main(int argc,char* argv[])
{

	int pid;
	int i;
	
	pid = fork();
	
	if(pid == -1)
	{
		return -1;
	}
	else if(pid != 0)
	{
		exit(EXIT_SUCCESS);
	}
	
	if (setsid ( ) == -1)	
	return -1;		
	
	/* set the working directory to the root directory */
	if (chdir ("/") == -1)
	return -1;


	/* close all open files--NR_OPEN is overkill, but works */
	//for (i = 0; i < NR_OPEN; i++)
	//close (i);	
	
	
	/* redirect fd's 0,1,2 to /dev/null */
	open ("/dev/null", O_RDWR);   /* stdin */
	
	dup (0);			/* stdout */
	
	dup (0);			/* stderror */
	
	/* do its daemon thing... */
	
return 0;	

}

