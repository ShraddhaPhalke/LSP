//WAP which accept file name from user and read whole file

#include<stdio.h>
#include<fcntl.h>

int main(int argc,char* argv[])
{
	int fd;
	int ret;
	char buff[1046];
	if(argc!=2)
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
	
	while(ret=read(fd,buff,sizeof(buff))!=0)
	{
	}
	
	if(ret == -1)
	{
		printf("Error:Unable to read the file\n");
	}	
	printf("Read contents are\n... %s\n",buff);
	
	return 0;
}
