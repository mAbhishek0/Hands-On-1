/*
============================================================================
Name : 23.c
Author : Abhishek Mandal
Description : Write a program to create a Zombie state of the running program.
Date : 1th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int pid;

	pid = fork();

	if(pid < 0){
		perror("fork error");
		exit(1);
	}

	if(pid == 0){
		printf("child process running with pid: %d\n", getpid());
		exit(0);
	}else{
		printf("parent process running with pid: %d\n", getpid());
		sleep(60);
	}

	return 0;
}
/*
============================================================================
output:
ab@ab:~$ gcc 23.c
ab@ab:~$ ./a.out
parent process running with pid: 17435
child process running with pid: 17436
ab@ab:~$ ps -l
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000    8168    8111  0  80   0 -  2944 do_wai pts/1    00:00:00 bash
0 T  1000   11031    8168  0  80   0 -   670 do_sig pts/1    00:00:00 a.out
0 T  1000   11904    8168  0  90  10 -   670 do_sig pts/1    00:00:00 a.out
4 R  1000   17566    8168  0  80   0 -  3478 -      pts/1    00:00:00 ps
ab@ab:~$ ps aux | grep defunct
ab         14218  0.0  0.0      0     0 pts/1    Z+   23:34   0:00 [a.out] <defunct>
============================================================================
*/	