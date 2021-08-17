/*	
	Program which creates two processess as process2 and process3 and our parent process wait till both the processess terminates. 
*/	

 #include<stdio.h>
 #include<stdlib.h>
 #include<unistd.h>
 
 int main(int argc,char * argv[])
 {
 
 	int pid = 0;
 	int i=0;
 	int childpid;
 	
 	printf("parent PID %d \n",getpid());
 	
 	for(i=1;i<=2;i++)
 	{
 		if((pid = fork()) == 0)
 		{
 			printf("process %d gets created with PID : %d\n",i,getpid());
 			printf("process%d's parent PID is : %d\n",i,getppid());
 			exit(0);
 	
 		}
 		else
 		{
 			childpid=wait(NULL);
 			printf("wait returned with child PID : %d\n",childpid);	
 		}
 	
 	}
 	
 	return 0;	
 }			
 
