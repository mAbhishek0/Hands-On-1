/*
============================================================================
Name : 21.c
Author : Abhishek Mandal
Description :Write a program, call fork and print the parent and child process id.
Date : 1th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main(){
	int pid;

	pid = fork();
	if(pid < 0){
		perror("fork error");
	}

	else if(pid == 0){
		printf("child process: pid = %d, parent pid = %d\n", getpid(), getppid());
	}
	else{
		printf("parent process: pid = %d, child pid = %d\n", getpid(), pid);
	}

	return 0;
}
/*
============================================================================
output:
ab@ab:~$ gcc 21.c
ab@ab:~$ ./a.out
parent process: pid = 15104, child pid = 15105
child process: pid = 15105, parent pid = 15104
============================================================================
*/	
