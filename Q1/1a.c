/*
============================================================================
Name : 1a.c
Author : Abhishek Mandal
Description :Create the following types of a files using (i) shell command (ii) system call
soft link (symlink system call)
Date: 25th Aug, 2025.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>

int main(){
	const char *originalFile = "original.txt";
	const char *softlink = "softlink.txt";


	int result = symlink(originalFile, softlink);

	if(result == 0){
		printf("soft link created.");
		printf("%s -> %s\n", softlink, originalFile);
	}
	else{
		perror("error creating softlink");
	}

	return 0;
}
/*
============================================================================
output:
ab@ab:~$ ./a.out
soft link created.softlink.txt -> original.txt
============================================================================
*/
