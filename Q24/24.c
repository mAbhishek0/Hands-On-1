/*
============================================================================
Name : 24.c
Author : Abhishek Mandal
Description : Write a program to create an orphan process.
Date : 1th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int pid = fork();

	if(pid == 0){
		sleep(10);
		printf("child process running with pid: %d, parent pid: %d\n", getpid(), getppid());
	}
	else{
		printf("parent exiting now with pid: %d, child pid: %d\n",getpid(), pid);
		exit(0);
	}
	return 0;
}
/*
============================================================================
output:
ab@ab:~$ gcc 24.c
ab@ab:~$ ./a.out
parent exiting now with pid: 9674, child pid: 9675
ab@ab:~$ child process running with pid: 9675, parent pid: 3015
============================================================================
*/	
