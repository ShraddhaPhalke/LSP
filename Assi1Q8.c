//WAP which accept file name from user  and read whole file

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
	
	fd = open(argv[1],O_RDONLY);
	
	if(fd == -1)
	{
		printf("unable to open file \n");
		return -1;
	}
	
	while((ret = read(fd,buf,sizeof(buf)) != 0))
	
	printf("file data is: \n %s",buf);
	

	return 0;
}	
