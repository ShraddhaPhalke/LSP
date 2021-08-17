// Program which accept file name which contains data of all file. we have to create all file again.



/*
 Application which is used to combine all regular files from the diretory into one regular file
*/

 #include<stdio.h>
 #include<unistd.h>
 #include<stdlib.h>
 #include<fcntl.h>
 #include<dirent.h>
 #include<sys/stat.h>
 #include <sys/types.h>
 #include<string.h>
 #include<malloc.h>
 
 
 //myexe filename
 //myexe   argv[1]     
 // argv[1] : name of file which contains merged data

 
 struct Fileinfo
 {
 	char fname[256];
 	int fsize;
 };
 	
 
 int main(int argc,char * argv[])
 {


 	char name[300];
 	int ret = 0;
 	int fddest =0,fdsrc=0;
 	struct Fileinfo fobj;
 	char* buff;
 
 
 	if(argc != 2)
	{
		printf("Error: Not sufficeient arguments\n");
		printf("usage : directory_name file_name\n");
		return -1;
	}
	
	
	fdsrc = open(argv[1],O_RDONLY);
	
	if(fdsrc == -1)
	{
		printf("unable to open a file\n");
		return -1;
	}
	
	while((ret = read(fdsrc,&fobj,sizeof(fobj)))!=0)	
	{
		printf("file name : %s size : %d\n",fobj.fname,fobj.fsize);
		fddest = creat(fobj.fname,0777);
		if(fddest == -1)
		{
		printf("unable to creat a file\n");
		return -1;
		}
		
		//dynamic memory for data to read
		buff=(char*)malloc(fobj.fsize);
		
		//read the data from merged file
		read(fdsrc,buff,fobj.fsize);
		
		//write the data into the newly created file
		write(fddest,buff,fobj.fsize);
		
		//free the memory
		free(buff);
		close(fddest);
		
	}
	close(fdsrc);
	
 
 return 0;
 }
