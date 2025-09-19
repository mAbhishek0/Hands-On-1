/*
============================================================================
Name : 7.c
Author : Abhishek Mandal
Description :Write a program to copy file1 into file2 ($cp file1 file2).
Date: 31th Aug, 2025.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
    int fd1, fd2;
    char buffer[1000];
    int n;

    fd1 = open("original.txt", O_RDONLY);
    if(fd1 == -1) {
	    perror("error opening file1");
	    exit(1);
    }

    fd2 = open("newfileforProgram7.txt", O_WRONLY | O_CREAT, 0644);

    while((n = read(fd1, buffer, sizeof(buffer))) > 0){
	    write(fd2, buffer, n);
    }

    close(fd1);
    close(fd2);

    return 0;
}

/*
============================================================================
output:
ab@ab:~$ gcc 7.c
ab@ab:~$ ./a.out
ab@ab:~$ cat newfileforProgram7.txt 
test for program 7.
ab@ab:~$ cat original.txt
test for program 7.
============================================================================
*/

