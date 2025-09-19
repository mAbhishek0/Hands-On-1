/*
============================================================================
Name : 5.c
Author : Abhishek Mandal
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 31th Aug, 2025.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h> 
#include<stdlib.h>

int main(){
    int fd[5];

    for(int i = 0; i < 5; i++){
	    char filename[20];
	    sprintf(filename, "file%d.txt", i + 1);

	    fd[i] = open(filename, O_CREAT | O_RDWR, 0644);
	    if(fd[i] < 0){
		    perror("open error");
		    exit(1);
	    }

	    printf("created %s with fd = %d\n", filename, fd[i]);

    }

    while(1){
	    sleep(10);
    }

    return 0;
}



/*
============================================================================
output:
ab@ab:~$ gcc 5.c
ab@ab:~$ ./a.out &
[4] 19075
created file1.txt with fd = 3
created file2.txt with fd = 4
created file3.txt with fd = 5
created file4.txt with fd = 6
created file5.txt with fd = 7
ab@ab:~$ ls -l /proc/19075/fd
total 0
lrwx------ 1 ab ab 64 Sep  1 14:44 0 -> /dev/pts/1
lrwx------ 1 ab ab 64 Sep  1 14:44 1 -> /dev/pts/1
lr-x------ 1 ab ab 64 Sep  1 14:44 103 -> /usr/share/code/v8_context_snapshot.bin
lrwx------ 1 ab ab 64 Sep  1 14:44 2 -> /dev/pts/1
lrwx------ 1 ab ab 64 Sep  1 14:44 3 -> /home/ab/file1.txt
lrwx------ 1 ab ab 64 Sep  1 14:44 4 -> /home/ab/file2.txt
l-wx------ 1 ab ab 64 Sep  1 14:44 40 -> /home/ab/.config/Code/logs/20250901T141149/ptyhost.log
lrwx------ 1 ab ab 64 Sep  1 14:44 41 -> 'socket:[60384]'
lrwx------ 1 ab ab 64 Sep  1 14:44 42 -> /dev/ptmx
lrwx------ 1 ab ab 64 Sep  1 14:44 5 -> /home/ab/file3.txt
lrwx------ 1 ab ab 64 Sep  1 14:44 6 -> /home/ab/file4.txt
lrwx------ 1 ab ab 64 Sep  1 14:44 7 -> /home/ab/file5.txt
============================================================================
*/
