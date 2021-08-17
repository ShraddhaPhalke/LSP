// program which is used to demonstrate concept of I/O operations

#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char argv[])
{
	int fd;
	char buff[1026];
	int ret;
	
	if(argc != 2)
	{
		printf("Error: Not sufficient arguments\n");
		return -1;
	}

	//Open file reading the data
	
	fd = open(argv[1],O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file \n");
		return -1;
	}
	
	ret = read(fd,buff,sizeof(buff));
	
	printf("Contents of file %s are : \n %s\n",argv[1],buff);
	
	//open file for writing into file

	fd = open(argv[1],O_WRONLY| O_TRUNC);
	
	if(fd == -1)
	{
		printf("Unable to open file \n");
		return -1;
	}
	
	printf("Enter the string that we want to write in file \n");
	scanf("%[^\n]",buff);

	ret = write(fd,buff,strlen(buff));
	if(ret != strlen(buff))
	{
		printf("Error: Unable to write whole contents\n");
	}
	
	close(fd);
	return 0;
}
	
