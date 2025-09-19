/*
============================================================================
Name : 16.c
Author : Abhishek Mandal
Description : Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
Date : 1th Sep, 2025.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd;
	struct flock lock;
	int choice;

	fd = open("lock.txt", O_RDWR | O_CREAT, 0666);
	if(fd == -1){
		perror("error opening file");
		exit(1);
	}

	printf("enter 1 for write lock and 2 for read lock:");
	scanf("%d", &choice);

	if(choice == 1){
		lock.l_type = F_WRLCK;
	}
	else{
		lock.l_type = F_RDLCK;
	}

	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	printf("locking file now...\n");

	if(fcntl(fd, F_SETLKW, &lock) == -1){
		perror("error locking file");
		exit(1);
	}

	printf("lock acquired, press enter to unlock.\n");
	getchar();
	getchar();

	lock.l_type = F_UNLCK;
	if(fcntl(fd, F_SETLK, &lock) == -1){
		perror("unlock failed");
		exit(1);
	}

	printf("lock released\n");
	close(fd);
	return 0;
}

/*
============================================================================
output:
ab@ab:~$ gcc 16.c
ab@ab:~$ ./a.out
enter 1 for write lock and 2 for read lock:1
locking file now...
lock acquired, press enter to unlock.

lock released
ab@ab:~$ ./a.out
enter 1 for write lock and 2 for read lock:2
locking file now...
lock acquired, press enter to unlock.

lock released
ab@ab:~$ ./a.out
enter 1 for write lock and 2 for read lock:1
locking file now...
lock acquired, press enter to unlock.

lock released
============================================================================
*/	