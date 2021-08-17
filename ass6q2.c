//	Program which create hole of size 1kb at the end of file

#include<string.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc,char * argv[])
{
	int fd;
	int ret=0;
	int writec=0;
	char buff[10] = {"helloworld"};
	
	fd=open("d.txt",O_WRONLY);
	
	if(fd == -1)
	{
		printf("Error:Unable to open a file\n");
		return -1;
	}
	
	ret = lseek (fd, (off_t) 1024, SEEK_END);
	printf("%d",ret);
	
	writec = write(fd,buff,sizeof(buff));
	if(writec == -1)
	{
		printf("unable to write \n");
		return -1;
	}
	
	printf("hole gets created\n");
	
	return 0;
}
		
