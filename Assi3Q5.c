//program which accept directory name and file name from user and check whether that file is present in that directory or not

/*
	Write a program which accept directory name and file name from user and check whether that file is available in that directory or not.
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

	if(argc != 3)
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
				if(strcmp(argv[2],(char*)entry->d_name)==0)
				{
					printf("%s file is present in directory\n",argv[2]);	
					break;
				}
	}
	
	// close that opened directory
	closedir(dir);
return 0;
}
