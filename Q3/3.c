/*
============================================================================
Name : 3.c
Author : Abhishek Mandal
Description :Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 25th Aug, 2025.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h> // contains creat()

int main(){
    int fd;
    
    fd = creat("myfile.txt", 0666);

    if(fd == -1){
        perror("creat failed");
        return 1;
    }
    printf("file created fd = %d\n", fd);
    return 0;
}

/*
============================================================================
output:
ab@ab:~$ gcc 3.c
ab@ab:~$ ./a.out
file created fd = 3
============================================================================
*/
