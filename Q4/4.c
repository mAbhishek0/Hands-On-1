/*
============================================================================
Name : 4.c
Author : Abhishek Mandal
Description :Write a program to open an existing file with read write mode. Try O_EXCL flag also
Date: 26th Aug, 2025.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h> 

int main(){
    int fd;

    fd = open("newfile.txt",O_CREAT | O_EXCL | O_RDWR);
    
    if(fd == -1){
        perror("open failed");
       	return 1;	
    }

    printf("file Opened fd = %d\n", fd);
    close(fd);
    return 0;	
}

/*
============================================================================
output:
ab@ab:~$ gcc 4.c
ab@ab:~$ ./a.out
open failed: File exists
ab@ab:~$ gcc 4.c
ab@ab:~$ ./a.out
file Opened fd = 3
============================================================================
*/
