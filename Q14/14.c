/*
============================================================================
Name : 14.c
Author : Abhishek Mandal
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date : 1th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
int main(int argc, char *argv[]){
	struct stat filestat;

	if(argc != 2){
		printf("usage: %s <filename>\n", argv[0]);
		exit(1);

	}

	if(stat(argv[1], &filestat) < 0){
		perror("stat error");
		exit(1);
	}

	if(S_ISREG(filestat.st_mode))
		printf("%s is a regular file\n", argv[1]);
	else if(S_ISDIR(filestat.st_mode))
		printf("%s is a directory\n", argv[1]);
	else if(S_ISCHR(filestat.st_mode))
		printf("%s is a character device file\n", argv[1]);
	else if(S_ISBLK(filestat.st_mode))
		printf("%s is a block device file\n", argv[1]);
	else if(S_ISFIFO(filestat.st_mode))
		printf("%s is a FIFO\n",argv[1]);
	else if(S_ISLNK(filestat.st_mode))
		printf("%s is a symbolic link\n", argv[1]);
	else if(S_ISSOCK(filestat.st_mode))
		printf("%s is a socket\n", argv[1]);
	else
		printf("%s is of unknown type\n", argv[1]);
	return 0;
}

/*
============================================================================
output:
ab@ab:~$ gcc 14.c
ab@ab:~$ ./a.out
usage: ./a.out <filename>
ab@ab:~$ ./a.out test.txt
usage: %s <filename>
test.txt is a regular file
ab@ab:~$ ./a.out /proc
/proc is a directory
============================================================================
*/	
