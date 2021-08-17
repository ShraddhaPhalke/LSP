// Program which accept directory name from user and copy first 10 bytes from all regular files into newly created file named as demo

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include<string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char* argv[])
{
	DIR *dir;
	struct dirent *entry;
	struct stat fileStat;
	char name[100] = {'\0'};
	char fname[100] = {'\0'};
	char buff[100] = {'\0'};
	int fdRead,fdWrite,readcnt,writecnt;
	fdRead = fdWrite = readcnt = writecnt = 0;

	if(argc != 2)
	{
		printf("Error: Not sufficeient arguments\n");
		return -1;
	}

	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}
	
	sprintf(fname,"%s/%s",argv[1],"Demo");
	
	if ((fdWrite = creat(fname,0666)) < 0)
	{
		printf("Unable to create new file\n");
		return -1;
	}
	
	while ((entry = readdir(dir)) != NULL)
	{
		
		sprintf(name,"%s/%s",argv[1],entry->d_name);		
		stat(name,&fileStat);	
		
		if(S_ISREG(fileStat.st_mode))
		{
			if ((fdRead = open(name,O_RDONLY)) < 0)
			{
				printf("Unable to open specified file\n");
				return -1;
			}
			readcnt = read(fdRead,buff,10); 
			
			if(writecnt = write(fdWrite,buff,readcnt) == -1)
			{
				printf("Problem in writting");
			}
					
		}
	}
	close(fdRead);
	close(fdWrite);
	
	return 0;
}						
