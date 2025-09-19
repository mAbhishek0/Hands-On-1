/*
============================================================================
Name : 12.c
Author : Abhishek Mandal
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date : 31th Aug, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int fd, flags;

	fd = open("test.txt", O_RDWR | O_APPEND);
	if(fd < 0){
		perror("error while opening file");
		exit(1);
	}

        flags = fcntl(fd, F_GETFL);
        if(flags < 0){
		perror("fcntl failed");
		exit(1);
	}
        switch(flags & O_ACCMODE){
		case O_RDONLY:
			printf("file is opened in READ ONLY mode\n");
			break;
		case O_WRONLY:
			printf("file is opened in WRITE ONLY mode\n");
			break;
		case O_RDWR:
			printf("file is opened in READ and WRITE mode\n");
			break;

	}

	if(flags & O_APPEND){
		printf("O_APPEND flag is set:writes to the end of the file\n");
	}

	if(flags & O_NONBLOCK){
		printf("O_NONBLOCK flag is set I/O calls won't block\n");
		}
	close(fd);
	return 0;
}
/*
============================================================================
output:
ab@ab:~$ gcc 12.c
ab@ab:~$ ./a.out
file is opened in READ and WRITE mode
O_APPEND flag is set:writes to the end of the file
============================================================================
*/	


