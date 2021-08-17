// Program which accept directory name from user and combine all contents of file from that directory into one file named as Allcombine

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include<string.h>
#include <sys/stat.h>
#include <fcntl.h> 

 struct Fileinfo
 {
 	char fname[256];
 	int fsize;
 };
 
int main(int argc,char* argv[])
{
	DIR *dp = NULL;
	struct dirent *dip = NULL;
	struct stat sobj;
	char name[300];
 	int ret = 0;
 	int fddest =0,fdsrc=0;
 	struct Fileinfo fobj;
 	char buff[1024];
 
 	if(argc != 2)
	{
		printf("Error: Not sufficeient arguments\n");
		printf("usage : directory_name \n");
		return -1;
	}
	
	dp = opendir(argv[1]);
	
	if (dp == NULL)
	{
		printf("Unable to open directory\n");
		return -1;
	}
	
	fddest = creat("Allcombine.txt",0777);
	
	if(fddest == -1)
	{
		printf("unable to create\n");
		closedir(fddest);
		return 0;
	}
	
	printf("Names of the files are\n");
	
	while((dip = readdir(dp)) != NULL)
	{
	
		sprintf(name,"%s/%s",argv[1],dip->d_name);
	
		stat(name,&sobj);
		
		if(S_ISREG(sobj.st_mode))
		{
			//fill the structure
			strcpy(fobj.fname,dip->d_name);
			fobj.fsize = sobj.st_size;
			
			//write the fileinfo structure into the file
			write(fddest,&fobj,sizeof(fobj));
			
			memset(&fobj,0,sizeof(fobj)); //zeroout the memory
			
			fdsrc = open(name,O_RDONLY);
			
			while((ret = read(fdsrc,&buff,sizeof(buff)) )!= 0)
			{
				write(fddest,buff,ret);
			}
			memset(buff,0,sizeof(buff));
			close(fdsrc);
			
			
			printf("%s : %lld\n",dip->d_name,sobj.st_size);
		}
		
	}
	
	closedir(dp);		
return 0;
}
	
