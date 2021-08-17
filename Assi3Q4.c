//program which accpet two files name from user and copy the contents of an existing file into newly created file

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int fd1,fd2;
	char buff[1024];
	long int ret1,ret2;
	
	fd1=open(argv[1],O_RDONLY);
	
	if(fd1 == -1)
	{
		printf("Error:Unable to open a file");
		return -1;
	}
	
	fd2=open(argv[2],O_CREAT | O_WRONLY);
	
	if(fd2 == -1)
	{
		printf("Error:Unable to open a file");
		return -1;
	}
	
	while(ret1=read(fd1,buff,1024) > 0)
	{
		ret2=write(fd2,buff,1024);
	}
	
	if(ret2 == -1)
	{
		printf("Error writting to the file");
	}
		
	
	close(fd1);
	close(fd2);
	return 0;
}			
	
