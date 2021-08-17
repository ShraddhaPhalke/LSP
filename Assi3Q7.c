/*
	Write a program which accept directory name from user and delete all files which are empty.
*/

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
	struct stat fileStat;	// Structure which stores all information of file.
	int max = 0;
	char name[100] = {'\0'};	

	if(argc != 2)
	{
		printf("Error: Not sufficeient arguments\n");
		return -1;
	}

	// Open the specified directory
	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}

	// Traverse directory
	while ((entry = readdir(dir)) != NULL)
	{
		// Use to create absolute path of file
		sprintf(name,"%s/%s",argv[1],entry->d_name);		
		stat(name,&fileStat);				
		
		// Check file size only if it is regular file
		if(S_ISREG(fileStat.st_mode))
		{		
			// Compaire file size
			if((int)fileStat.st_size == 0)
			{
				// Delete the specified file
				remove(name);
			}
		}
		memset(&fileStat,0,sizeof(fileStat));
	}
	
	// close that opened directory
	closedir(dir);
return 0;
}
