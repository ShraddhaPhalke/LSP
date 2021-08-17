//	Program which accept file name which contains data of all file. We have to print all file names whose size is greater than 10 bytes

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include<string.h>
#include <sys/stat.h>
#include <fcntl.h> 

int main(int argc,char* argv[])
{
	FILE *in;
	struct stat fileStat;


	if(argc != 2)
	{
		printf("Error: Not sufficeient arguments\n");
		return -1;
	}
	
	in = fopen(argv[1], "r");
	   
	if(!in)
        {
		printf("Error:Unable to open a file\n");
		return -1;
        }
        
        while(fread (&fileStat, sizeof (struct stat), 1, in))
	{
		if((int)fileStat.st_size > 10)
		{
			printf("%d\n",(int)fileStat.st_size);
		}
	}
	fclose(in);
	return 0;
}			
