/*
============================================================================
Name : 6.c
Author : Abhishek Mandal
Description :Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 31th Aug, 2025.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h> 
int main(){
    char buffer[100];
    int n;
    n = read(0, buffer, sizeof(buffer));

    write(1, buffer, n);
    return 0;
}


/*
============================================================================
output:
ab@ab:~$ gcc 6.c
ab@ab:~$ ./a.out
testing program 6 now!
testing program 6 now!
============================================================================
*/
