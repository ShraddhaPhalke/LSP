//WAP which accept file name from user and open that file

#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd;
	
	fd=open(argv[1],O_RDONLY);
	
	if(fd == -1)
	{
		printf("Unable to open a file\n");
		return -1;
	}	
	
	printf("File is successfully opened with file descriptor %d in read mode \n",fd);
	return 0;
}
