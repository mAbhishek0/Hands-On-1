/*
============================================================================
Name : 8.c
Author : Abhishek Mandal
Description :Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 31th Aug, 2025.
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
int main(){
    int fd;
    char ch;
    char buffer[1000];
    int i = 0;

    fd = open("linebyline.txt", O_RDONLY);
    if(fd == -1){
	    perror("error opening file");
	    exit(1);
    }

    while(read(fd, &ch, 1) > 0){
	    buffer[i++] = ch;

	    if(ch == '\n'){
		    buffer[i] = '\0';
		    write(1, buffer, i);
		    i = 0;
	    }
    }
    close(fd);
    return 0;
}
/*
============================================================================
output:
ab@ab:~$ cat linebyline.txt
this
is
a
test
file
for
program
8
ab@ab:~$ gcc 8.c
ab@ab:~$ ./a.out
this
is
a
test
file
for
program
8
============================================================================
*/
