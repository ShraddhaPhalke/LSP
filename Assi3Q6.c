//program which accept two directory name from user and move all files from source directory to destination directory

/*
	Write a program which accept two directory name and move all file 	from source directory to destination directory.
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
	char oldpath[256] = {'\0'};
	char newpath[256] = {'\0'};
	
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
		// Form source and destination path
		sprintf(oldpath,"%s/%s",argv[1],entry->d_name);
		sprintf(newpath,"%s/%s",argv[2],entry->d_name);
		
		// Move that file		
		rename(oldpath,newpath);
		memset(&oldpath,0,sizeof(oldpath));
		memset(&newpath,0,sizeof(newpath));
	}
	
	// close that opened directory
	closedir(dir);
return 0;
}
