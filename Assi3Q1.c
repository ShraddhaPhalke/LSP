//program which accept directory name from user and print all file names from that directory

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int main(int argc,char *argv[])
{
	DIR *dir;
	
	struct dirent *entry;
	
	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}

	printf("File names: \n");
	
	while ((entry = readdir(dir)) != NULL)
	{
	      printf("Name: %s\n", entry->d_name);
	}
	
	closedir(dir);
return 0;
}
