//WAP which accept file name from user and open that file and if file is not opend properly then display error message properly

#include<stdio.h>
#include<fcntl.h>

int main(int argc,char* argv[])
{
	int fd;
	
	if( argc != 2)
	{
		printf("Error:No sufficient arguments\n");
		return -1;
	}	
	
	fd=open(argv[1],O_RDONLY);
	
	if(fd == -1)
	{
		printf("unable to open file \n");
		return -1;
	}
	else
	{
		printf("File is successfully opened with file descriptor %d in read mode \n",fd);
	}
	return 0;
}
