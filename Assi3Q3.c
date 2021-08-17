//program which accept directory name from user and print name of such file having largest size

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc,char *argv[])
{
	DIR *dir;
	struct dirent *entry;
	struct stat fileStat;
	int ret;
	int maxsize=0,filesize=0;
	char name[50];
	char fname[50];
	
	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}
	
	while ((entry = readdir(dir)) != NULL)
	{
	     // printf("Name: %s\n", entry->d_name);
	      sprintf(name,"%s/%s",argv[1],entry->d_name);
	      ret=stat(name,&fileStat);
	      if(ret == -1)
	      {
			printf("stat function fail\n");
			return -1;
	      }
	      
	      if(S_ISREG(fileStat.st_mode))
	      {		
	      		filesize=(int)fileStat.st_size;
	      
	      		if(filesize > maxsize)
	     		{
	      			maxsize=filesize;
	      			strcpy(fname,entry->d_name);
	      		}
	      }		
	}
	printf("file name is %s having max file size %d\n",fname,maxsize);
	
	closedir(dir);
return 0;
}
