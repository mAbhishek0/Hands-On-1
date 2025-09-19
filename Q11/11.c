/*
============================================================================
Name : 11.c
Author : Abhishek Mandal
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 31th Aug, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd, fdDup1, fdDup2, fdDup3;

	fd = open("11test.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
	if(fd < 0){
		perror("file opening error");
		exit(1);
	}

	fdDup1 = dup(fd);
	if(fdDup1 < 0){
		perror("error while duplicating");
		exit(1);
	}

	fdDup2 = dup2(fd, 100);
	if(fdDup2 < 0){
		perror("error while running dup2");
		exit(1);
	}

	fdDup3 = fcntl(fd, F_DUPFD, 200);
	if(fdDup3 < 3){
		perror("error while running fcntl");
		exit(1);
	}
	write(fd, "written by fd\n", 14);
	write(fd, "written by dup\n", 15);
	write(fd, "written by dup2\n", 16);
	write(fd, "written by fcntl\n", 17);

	close(fd);
	close(fdDup1);
	close(fdDup2);
	close(fdDup3);

	return 0;

}
/*
============================================================================
output:
ab@ab:~$ gcc 11.c
ab@ab:~$ ./a.out
ab@ab:~$ cat 11test.txt
written by fd
written by dup
written by dup2
written by fcntl
============================================================================
*/
