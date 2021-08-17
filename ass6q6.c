// Program which accept directory name from user and create hole in file if size is less than 1kb & if it is grater than 1kb then truncate the remaining data.

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include<string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) 
{
	DIR *dir;
	struct dirent *entry;
	struct stat fileStat;
	int fd,ret;
	char name[100] = {'\0'};
	int size=1024;	
	char buff[10]={"helloworld"};
	int writec;
	
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
	
	
	while ((entry = readdir(dir)) != NULL)
	{
	
		sprintf(name,"%s/%s",argv[1],entry->d_name);		
		stat(name,&fileStat);				
		
		// Check file size only if it is regular file
		if(S_ISREG(fileStat.st_mode))
		{		
			// Compaire file size with 
			if((int)fileStat.st_size < size)
			{
				fd=open(name,O_WRONLY);
	
				if(fd == -1)
				{
					printf("Error:Unable to open a file\n");
					return -1;
				}
	
				ret = lseek (fd, (off_t) 1024, SEEK_END);
				
	
				writec = write(fd,buff,sizeof(buff));
				if(writec == -1)
				{
					printf("unable to write \n");
					return -1;
				}
				close(fd);
			}
			else if((int)fileStat.st_size > size)
			{
			
				fd = open(argv[1],O_WRONLY);
	
				if(fd == -1)
				{
					printf("unable to open file \n ");
					return -1;
				}
	
				ret = ftruncate(fd,1024);
	
				if (ret == -1)
				{
					printf("unable to truncate the data \n");
					return 0;
				}

			}
		}	
	}		
	return 0;
}		
			
				
			
			
