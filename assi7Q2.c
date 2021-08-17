/*	
	Program which createss three level process hierarchy where process 1 creates process 2 and it internally creates process 3.
*/	

 #include<stdio.h>
 #include<stdlib.h>
 #include<unistd.h>
 
 int main(int argc,char * argv[])
 {
 
 
 	int ret = 0;
 	
 	ret = fork();
 	
 	if(ret == 0)
 	{
 	
 		printf("Process1 gets created with PID : %d\n",getpid());
 		printf("Process1 parent id is  PID : %d\n",getppid());
 		
 		ret = fork();
 		
 		if(ret == 0)
 		{
 			printf("Process2 gets created with PID : %d\n",getpid());	
 			printf("Process2's parent id is  PID : %d\n",getppid());
 			
 			 ret = fork();
 			 
 			 if(ret == 0)
 			 {
 				 printf("Process3 gets created with PID : %d\n",getpid());	
 				 printf("Process3's parent id is  PID : %d\n",getppid());	
 			 }
 			 else
 			{
 				wait(NULL);
 				printf("parent of process3 is ending with pid :%d\n",getpid());
 			}	
 		}
 		else
 		{
 			wait(NULL);
 			printf("parent of process2 is ending with pid :%d\n",getpid());
 		}	
 		
 	}
 	else
 	{
 	
 		wait(NULL);
 		printf("parent of process1 is ending with pid :%d\n",getpid());
 		
 	}
 exit(0);
 }
