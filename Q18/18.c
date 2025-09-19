/*
============================================================================
Name : 18.c
Author : Abhishek Mandal
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date : 7th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

struct record{
	int recordid;
	int value;
};

int main(){
	struct record r1 = {1, 1};
	struct record r2 = {2, 2};
	struct record r3 = {3, 3};

	int fd = open("18input.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);

	struct record arr[] = {r1, r2, r3};

	write(fd, &arr, sizeof(arr));
	write(fd, &arr, sizeof(arr));
	write(fd, &arr, sizeof(arr));
	
	return 0;
	}
