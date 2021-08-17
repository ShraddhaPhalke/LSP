// Program which writes structure in file. Structure should contains information of employee

#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee
	{
		int eid;
		char name[100];
		int salary;
	};

int main(int argc,char* argv[])
{
	int fd=0;
	struct Employee obj;
	
	
	fd = open (argv[1],O_WRONLY);
	
	if(fd == -1)
	{
		printf("Error:Unable to open a file\n");
		return -1;
	}
	
	memset(&obj,0,sizeof(obj)); 
	obj.eid = 1;
	strcpy(obj.name,"shraddha");
	obj.salary = 30000;
	
	write(fd,&obj,sizeof(obj));
	//memset(&obj,0,sizeof(obj)); 
        	
	close(fd);
	return 0;
}
