// Program which accept directory name from user and write information of all regular file in and then read the contents from that file.

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
	FILE *out,*in;
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
	
	//open data5 file for writing
	out = fopen ("data5", "w");
	
	if(!out)
	{
		printf("Error:Unable to open a file\n");
		return -1;
	}

	
	while ((entry = readdir(dir)) != NULL)
	{
		
		sprintf(name,"%s/%s",argv[1],entry->d_name);		
		stat(name,&fileStat);	
		if(S_ISREG(fileStat.st_mode))
		{
			if (!fwrite (&fileStat, sizeof (struct stat), 1, out)) 
	               {
				printf("error in writing\n");
				return -1;
	               }
	        } 
	  }   
	  fclose(out);   
	
	   //open data5 file for reading               
	   in = fopen("data5", "r");
	   
	   if(!in)
	   {
		printf("Error:Unable to open a file\n");
		return -1;
	   }
	   //reading the file till the end
	   while(fread (&fileStat, sizeof (struct stat), 1, in))
	   {
	   	printf("File Size : \t%d bytes\n",(int)fileStat.st_size);
		printf("Number of Links : \t%d\n",(int)fileStat.st_nlink);
		printf("File inode Number: \t\t%d\n",(int)fileStat.st_ino);
		printf("File system number: \t\t%d\n",(int)fileStat.st_dev);
		printf("Number of blocks allocated for file\t\t%d\n",(int)fileStat.st_blocks);
           }
           
           fclose(in);	 
	return 0;
}
	
	
