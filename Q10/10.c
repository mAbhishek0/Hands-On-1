/*
============================================================================
Name : 10.c
Author : Abhishek Mandal
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 31th Aug, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd;
	char buf1[] = "BEFORE!!!!";
	char buf2[] = "AFTER!!!!!";
	off_t offset;

	fd = open("testfile.txt", O_RDWR | O_CREAT, 0644);
	if(fd == -1){
		perror("error opening file");
		exit(1);
	}

	if(write(fd, buf1, 10) != 10){
		perror("error writing to file");
		exit(1);
	}

	offset = lseek(fd, 10 , SEEK_CUR);
	if(offset == -1){
		perror("lseek error");
		exit(1);
	}

	printf("current offset after lseek: %ld\n", (long)offset);

	if(write(fd, buf2, 10) != 10){
		perror("write error");
		exit(1);
	}

	close(fd);
	return 0;
}

/*
============================================================================
output:
ab@ab:~$ gcc 10.c
ab@ab:~$ ./a.out
current offset after lseek: 20
============================================================================
*/
