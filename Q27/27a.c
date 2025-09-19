/*
============================================================================
Name : 27a.c
Author : Abhishek Mandal
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
Date : 5th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	printf("execl:\n");
	execl("/bin/ls", "ls", "-Rl", NULL);
	perror("execl error");

	return 0;
}
/*
============================================================================
output:
ab@ab:~$ cc 27a.c
ab@ab:~$ ./a.out
execl:
.:
total 396
-rw-rw-r-- 1 ab ab  1182 Aug 31 21:54  10.c
-rw-rw-r-- 1 ab ab  1474 Sep  1 00:24  11.c
-rw-r--r-- 1 ab ab    62 Aug 31 23:28  11test.txt
-rw-rw-r-- 1 ab ab  1386 Sep  1 00:24  12.c
-rw-rw-r-- 1 ab ab  1550 Sep  1 14:49  13.c
-rw-rw-r-- 1 ab ab  1599 Sep  1 15:11  14.c
-rw-rw-r-- 1 ab ab  4525 Sep  1 15:26  15.c
-rw-rw-r-- 1 ab ab  1739 Sep  1 16:14  16.c
-rw-rw-r-- 1 ab ab   538 Sep  1 16:17  17.c
-rw-rw-r-- 1 ab ab   455 Sep  1 18:09  18.c
-rw-rw-r-- 1 ab ab    12 Aug 19 14:26  19082025.txt
-rw-rw-r-- 1 ab ab   997 Sep  1 23:06  19.c
.....
============================================================================
*/