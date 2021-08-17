
         // Program which accept directory name from user and create new directory of that name

#include<stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include<string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
	int ret;
	char* dirname;
	
	if(argc != 2)
	{
		printf("Error: Not sufficeient arguments\n");
		return -1;
	}
	
	dirname= argv[1];
	
	ret=mkdir(dirname, 0777);
	
	if(ret == 0)
	{
		printf("Directory gets successfully created\n");
	}
	else if(ret == -1)
	{
		printf("Error: Unable to create directory");
	}
	return 0;
}	
