/*
============================================================================
Name : 26b.c
Author : Abhishek Mandal
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date : 5th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	printf("runner program now running and now will run child program.\n");

	execl("./demo2", "./demo2", "from parent program", NULL);

	perror("execl error");

	return 0;
}
/*
============================================================================
output:
ab@ab:~$ cc 26b.c
ab@ab:~$ ./a.out
runner program now running and now will run child program.
hello from demo program: from parent program
============================================================================
*/
