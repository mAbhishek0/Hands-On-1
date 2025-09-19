/*
============================================================================
Name : 22.c
Author : Abhishek Mandal
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date : 1th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd;
	int pid;
	

	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd < 0){
		perror("error while opening file");
		exit(1);
	}
	
    pid = fork();

	if(pid == 0){
		char childMessage[] = "this is written by the child prcess.\n";
		write(fd, childMessage, sizeof(childMessage) - 1);
	}else {
		char parentMessage[] = "this is written by the parent process.\n";
		write(fd, parentMessage, sizeof(parentMessage) - 1);
	}
	close(fd);
	return 0;
}

/*
============================================================================
output:
ab@ab:~$ gcc 22.c
ab@ab:~$ ./a.out
ab@ab:~$ cat output.txt
this is written by the parent process.
this is written by the child prcess.
============================================================================
*/	

