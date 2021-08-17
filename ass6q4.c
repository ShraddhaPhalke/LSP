// Program which accept directory name from user and delete all such files whose size is greater than 100 bytes

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
	char name[100] = {'\0'};
	
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
		
		if(S_ISREG(fileStat.st_mode))
		{		
		
			if( (int)fileStat.st_size > 100)
			{
				remove(name);
			}
		}
		memset(&fileStat,0,sizeof(fileStat));
	}
	 
	closedir(dir);
        return 0;
 } 
				
