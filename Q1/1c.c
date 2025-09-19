/*
============================================================================
Name : 1c.c
Author : Abhishek Mandal
Description :Create the following types of a files using (i) shell command (ii) system call
FIFO (mkfifo Library Function or mknod system call)
Date: 25th Aug, 2025.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    const char *fifo = "myfifo";
    if (mkfifo(fifo, 0666) == -1){
        perror("mkfifo");
        return 1;
    }

    printf("Fifo created: %s\n", fifo);
    return 0;
}

/*
============================================================================
output:
ab@ab:~$ ./a.out
Fifo created: myfifo
============================================================================
*/
