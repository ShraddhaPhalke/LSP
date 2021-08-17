// Program which accept two files names from user and check whether contents of that two files are equal or not

#include<stdio.h>
#include<string.h>

int main(int argc,char * argv[])
{
	FILE *fp1;
	FILE *fp2;
	char ch1,ch2;
	int err = 0 , pos=0 ,line =1;
	
	if(argc != 3)
	{
		printf("Error: Not sufficeient arguments\n");
		return -1;
	}
	
	fp1 = fopen(argv[1],"r");
	fp2 = fopen(argv[2],"r");
	
	if(fp1 == NULL || fp2 == NULL)
	{
		printf("unable to open file\n");
		return -1;
	}
	
	while(ch1 != EOF && ch2 != EOF)
	{
		pos++;
		
		if(ch1 == "\n" && ch2 =="\n")
		{
			line++;
			pos = 0;
		}
		
		if(ch1 != ch2)
		{
			err++;
			printf("contents of the files are not equal \n");
			break;
		}
		ch1 = fgetc(fp1);
		ch2 = fgetc(fp2);
	 }
	 if(err == 0)
	 {
	 	printf("contents of the files are equal \n");
	 }
	 
	 fclose(fp1);
	 fclose(fp2);
	 
	return 0;
} 	
		
