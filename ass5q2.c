// Program which accept file name from user and which contains information of employee,we have to read all contents of that file

#include<stdio.h>

struct Employee
	{
		int eid;
		char name[100];
		int salary;
	}obj1 = {1,"shraddha",30000};
int main(int argc,char* argv[])
{
	int fd=0;
	
	
	if(argc != 2)
	{
		printf("Error:Not sufficient arguments\n");
		return -1;
	}
	
	fd = open(argv[1],O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error:Unable to open a file\n");
		return -1;
	}
	
	read(fd,buff,sizeof(buff));

	printf ("eid=\"%d\" name=%s salary=%d\n",obj1.eid, obj1.name, obj1.salary);
									
	return 0;
}		
