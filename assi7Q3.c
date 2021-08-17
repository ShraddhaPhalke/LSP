/*	
	Program which creates three different processess internally as process2,process3,process4.
*/	


#include<stdio.h>
 #include<stdlib.h>
 #include<unistd.h>
 
 int main(int argc,char * argv[])
 {
 
 	int i=1;

 	
 	for(i=2;i<=4;i++)
 	{
 		
 		if((fork()) == 0)
 		{
 			printf("process %d gets created with PID : %d\n",i,getpid());
 			printf("process%d's parent PID is : %d\n",i,getppid());
 			exit(0);
 		}
 		else
 		{
 		}

 	}
 		
 return 0;	
 }	
