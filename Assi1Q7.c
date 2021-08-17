//WAP which accept file name and read first 5 characters from it

#include<stdio.h>
#include<fcntl.h>

int main(int argc,char * argv[])
{
	int fd;
	char buf[100];
	int ret;
	
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
	
	ret=read(fd,buf,5);
	
	printf("Read contents are \n %s\n",buf);
	
	return 0;
}	
