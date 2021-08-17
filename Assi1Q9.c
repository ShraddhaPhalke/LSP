//WAP which accept file name and string from user and write that string into file

#include<stdio.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{

	int fd,ret;
	if( argc != 3)
	{
		printf("Error:No sufficient arguments\n");
		return -1;
	}	
	
	fd=open(argv[1],O_RDWR);
	
	ret = write(fd,argv[2],sizeof(argv[2]));
	
	if(ret == -1)
	{
		printf("unable to write into file\n");
		return -1;
	}	
	

	return 0;
}	

