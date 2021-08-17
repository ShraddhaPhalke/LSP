//program which accept directory name from user and print all files name and its types from that file

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include<string.h>

int main(int argc,char *argv[])
{
	DIR *dir;
	
	struct dirent *entry;
	
	struct stat buf;
	
	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}
	
	printf("File names: \n");
	
	while ((entry = readdir(dir)) != NULL)
	{

	      printf("Name: %s\n", entry->d_name);
	      
	      if (stat(entry->d_name, &buf) < 0)
	      {
	       	printf("Error while retriving statistics of file\n");
			return -1;
	      }
	      
	      if (S_ISREG(buf.st_mode))
	      {
	       	printf("Regular file");
	      }
	      else if (S_ISDIR(buf.st_mode))
	      {
			printf("Directory");
	      }
	      else if (S_ISCHR(buf.st_mode))
	      {
			printf("Character special fiel");
	      }
	      else if (S_ISBLK(buf.st_mode))
	      {
			printf("Block special file");
	      }
	      else if (S_ISFIFO(buf.st_mode))
	      {
			printf("FIFO");
	      }
	      else if (S_ISLNK(buf.st_mode))
	      {
			printf("Symbolic link");
	      }
	      else if (S_ISSOCK(buf.st_mode))
	      {
	 		printf("Socket");
	      }
	      else
	      {
			printf("File type is unknown");
	      }

              printf("\n");
	}
	
	closedir(dir);
return 0;
}
