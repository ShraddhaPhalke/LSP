//WAP which aceept file name from user and write string in that file
#include<stdio.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
	int fd;
	int ret;
	char buff[]="marvellous";
	
	fd = open(argv[1],O_RDWR);
	if(fd == -1)
	{
		printf("Unable to open file \n");
		return -1;
	}
	
	ret=write(fd,buff,sizeof(buff));
	
	if(ret != sizeof(buff))
	{
		printf("Unable to write contents\n");
		return -1;
	}
	
	printf("file gets successfully written");
	close(fd);
	
	return 0;
}	
	
