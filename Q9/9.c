/*
============================================================================
Name : 9.c
Author : Abhishek Mandal
Description :Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 31th Aug, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>

int main(int argc, char * argv[]){
	struct stat fileStat;

	if(argc != 2){
		printf("usage: %s <filename>\n", argv[0]);
		exit(1);
	}

	if(stat(argv[1], &fileStat) < 0){
		perror("stat error");
		exit(1);
	}
	
	printf("file: %s\n", argv[1]);
	printf("inode: %ld\n", (long)fileStat.st_ino);
	printf("number of hard links: %ld\n", (long)fileStat.st_nlink);
	printf("uid: %d\n", fileStat.st_uid);
	printf("gid: %d\n", fileStat.st_gid);
	printf("size: %ld bytes\n", (long)fileStat.st_size);
	printf("block size: %ld bytes\n", (long)fileStat.st_blksize);
	printf("number of blocks: %ld\n", (long)fileStat.st_blocks);
	printf("time of last acces: %s", ctime(&fileStat.st_atime));
	printf("time of lastmodification: %s", ctime(&fileStat.st_mtime));
	printf("time of alst change: %s", ctime(&fileStat.st_ctime));

	return 0;
}

/*
============================================================================
output:
ab@ab:~$ gcc 9.c
ab@ab:~$ ./a.out linebyline.txt
file: linebyline.txt
inode: 3682213
number of hard links: 1
uid: 1000
gid: 1000
size: 34 bytes
block size: 4096 bytes
number of blocks: 8
time of last acces: Sun Aug 31 19:10:01 2025
time of lastmodification: Sun Aug 31 18:50:39 2025
time of alst change: Sun Aug 31 18:50:39 2025
============================================================================
*/
