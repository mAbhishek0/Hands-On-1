/*
============================================================================
Name : 1b.c
Author : Abhishek Mandal
Description :Create the following types of a files using (i) shell command (ii) system call
ard link (link system call)
Date: 25th Aug, 2025.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
int main(){
	const char* originalfile = "original.txt";
	const char* hardlink = "hardlinkC.txt";

	int res = link(originalfile, hardlink);

	if(res == 0){
		printf("hardlink created successfully \n");
		printf("%s -> %s", originalfile, hardlink);
	}
	else{
		perror("hardlink creation failed");
	}

	return 0;
}

/*
============================================================================
output:
ab@ab:~$ ./a.out
hardlink created successfully 
============================================================================
*/
