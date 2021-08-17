//WAP which accept file name and mode from user and then open that file in specified mode

/*
	Accept file name and mode in which we want to open that file from user
	and open that file.
	First argument is name of file and second argument is mode in which 		we want to open file.
	Second argument should be from read / write / readwrite / create /truncate 
*/

// This program demonstate open system call

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int fd = 0;
	int mode = 0;

	if(argc != 3)
	{
		printf("Error: Insufficient arguments\n");
		return -1;
	}
	// Opening file in read mode
	// Syntax : int open(char *path_name,mode_of_file);
	//If success then it will return the proper file descriptor else return -1.
	
	if(strcmp(argv[2],"read") == 0)
	{
		mode = O_RDONLY;
	}
	else if(strcmp(argv[2],"write") == 0)
	{
		mode = O_WRONLY;
	}
	else if(strcmp(argv[2],"read_write") == 0)
	{
		mode = O_RDWR;
	}
	else if(strcmp(argv[2],"create") == 0)
	{
		mode = O_CREAT;
	}
	else if(strcmp(argv[2],"truncate") == 0)
	{
		mode = O_WRONLY | O_TRUNC;
	}
	else
	{
		printf("Invalid argument\n");
		return -1;
	}

	fd = open(argv[1],mode);	// absolute path given
	if(fd == -1)
	{
		printf("Unable to open the file\n");
	}
	else
	{
		printf("File is successfully opened with file descriptor %d in %s mode \n",fd,argv[2]);
	}
	close(fd);	// closes the opened file
	return 0;

}
