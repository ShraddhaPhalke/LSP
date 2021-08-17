// Program which accept file name from user and offset, remove all the data from that offset.

#include<stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char * argv[])
{
	int ret;
	int fd;
	
	if(argc != 3)
	{
		printf("Error: Not sufficeient arguments\n");
		return -1;
	}
	
	fd = open(argv[1],O_WRONLY);
	
	if(fd == -1)
	{
		printf("unable to open file \n ");
		return -1;
	}
	
	ret = ftruncate(fd,(off_t)argv[2]);
	
	if (ret == -1)
	{
		printf("unable to truncate the data \n");
		return -1;
	}
	
	return 0;
}		
