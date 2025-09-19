/*
============================================================================
Name : 25.c
Author : Abhishek Mandal
Description : Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).
Date : 1th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int pid1, pid2, pid3;

	pid1 = fork();
	if(pid1 == 0){
		printf("child 1 is running with pid: %d\n", getpid());
		sleep(2);
		exit(0);
	}

	pid2 = fork();
	if(pid2 == 0){
		printf("child 2 is running with pid: %d\n", getpid());
		sleep(3);
		exit(0);
	}

	pid3 = fork();
	if(pid3 == 0){
		printf("child 3 is running with pid: %d\n", getpid());
		sleep(4);
		exit(0);
	}
	printf("parent waiting for child 2 with pid: %d\n", pid2);
	waitpid(pid2, NULL, 0);
	printf("child 2 finished running\n");
	wait(NULL);
	wait(NULL);
	return 0;
}
/*
============================================================================
output:
ab@ab:~$ gcc 25.c
ab@ab:~$ ./a.out
child 1 is running with pid: 13357
child 2 is running with pid: 13358
parent waiting for child 2 with pid: 13358
child 3 is running with pid: 13359
child 2 finished running
============================================================================
*/	
