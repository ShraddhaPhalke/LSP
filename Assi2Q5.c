//WAP which accept file name and number of bytes from user and read that number of bytes from file

#include<stdio.h>
#include<fcntl.h>

int main(int argc,char* argv[])
{
	int fd;
	int ret;
	char buff[sizeof(argv[2])];
	if(argc != 3)
	{
		printf("Error:Insufficient number of arguments \n");
		return -1;
	}
	
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("Error:Unable to open a file \n");
		return -1;
	}
	
	ret=read(fd,buff,sizeof(argv[2]));
	
	if(ret == -1)
	{
		printf("Error:Unable to read the file\n");
	}	
	printf("Read contents are %s\n",buff);
	
	return 0;
}		
