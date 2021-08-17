 /* 
 	Program which creates one child process, and parent process wait till its child process terminates.
 */	
 
 #include<stdio.h>
 #include<stdlib.h>
 #include<unistd.h>
 
 int main(int argc,char * argv[])
 {
 
 	int ret =0;
 	int childpid;
 	int status =0;
 	
 	ret = fork();
 	
 	if( ret == 0)
 	{
 		execl("./myexe",NULL,NULL);

 		
 	}
 	else
 	{
 		printf("Parent process is waiting\n");
 		childpid = wait(&status);
 		printf("Child process gets ternimated and return child PID :%d\n",childpid);
 	}
 
 return 0;
 }
