//program which accept file name and on mode and that program check whether that process can access that file in accepted mode or not


/*
	Accept file name and mode in which we want to check the accessibility.
	First argument is name of file and second argument is mode
	Second argument should be from read / write / execute
*/

// This program demonstates accessibility of the files

#include<string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc,char *argv[])
{
	int mode = 0;

// access() checks whether the calling process can access the file pathname.  If pathname is a symbolic link, it is dereferenced.
//On  success  (all requested permissions granted), zero is returned.  
// On error (at least one bit in mode asked for a permission that is denied, or some other error occurred), -1 is returned,

	if(argc != 3)
	{
		printf("Error: Insufficient arguments\n");
		return -1;
	}
	
	if(strcmp(argv[2],"read") == 0)
	{
		mode = R_OK;
	}
	else if(strcmp(argv[2],"write") == 0)
	{
		mode = W_OK;
	}
	else if(strcmp(argv[2],"execute") == 0)
	{
		mode = X_OK;
	}

	if (access(argv[1],mode) < 0)
	{
		printf("Our process can not access this file for %s purpose\n",argv[2]);
	}
	else
	{
		printf("Our process has %s access\n",argv[2]);
	}

	return 0;
}
