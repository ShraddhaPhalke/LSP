/*
	Program which is used to disply Environment of our running process.
*/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
extern char ** environ;
int main(int argc,char *argv[])
{
	char **env =environ;
	
	for(;*env!=NULL;++env)
	{
		printf("_________________________________________________________\n");
		printf("%s \n",*env);
	}	


return 0;
}
