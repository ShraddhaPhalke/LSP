// Program which accept directory name and file name from user and create file in that directory.

#include<stdio.h>
#include<fcntl.h>
#include <dirent.h>

int main(int argc,char * argv[])
{

	int fd;
	char fname[100];
	
	if(argc != 3)
	{
		printf("Error: Not sufficient arguments\n");
		return -1;
	}
	
	sprintf(fname,"%s/%s",argv[1],argv[2]);
	
	fd = creat(fname,0777);
	
	if(fd == -1)
	{
		printf("unable to create a file\n");
		return 0;
	}
	
	return 0;
}		
