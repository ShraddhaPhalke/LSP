// Program which accept file name and position from user and read 20 bytes from that position


#include <sys/types.h>
#include<stdio.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int fd=0;
	int position=0;
	int ret;
	char buff[100];
	
	if(argc != 3)
	{
		printf("Error: Not sufficeient arguments\n");
		return -1;
	}
	
	fd=open(argv[1],O_RDONLY);
	
	if(fd == -1)
	{
		printf("Unable to open specified file\n");
		return -1;
	}
	
	if(strcmp(argv[2],"start") == 0)
	{
		position = SEEK_SET;
	}
	else if(strcmp(argv[2],"current") == 0)
	{
		position = SEEK_CUR;
	}
	else if(strcmp(argv[2],"end") == 0)
	{
		position = SEEK_END;
	}
	
	
	ret = pread(fd,buff,20,position);
	
	printf("Contents of file %s are : \n %s\n",argv[1],buff);
	
	close(fd);
	
	return 0;
}
		
