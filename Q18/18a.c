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
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

struct record {
	int recordid;
	int val;
};
int main(){
	int fd = open("/home/ab/18input.txt", O_RDWR);
	struct flock wrlock = {F_WRLCK, SEEK_SET, 0, sizeof(struct record), getpid()};

	int recordid;
	printf("enter record to be locked: ");
	scanf("%d", &recordid);

	if(recordid > 3)
		printf("invalid record id");
	else {
		printf("locking...\n");
		wrlock.l_start = (recordid - 1) * sizeof(struct record);
		wrlock.l_len = sizeof(struct record);
		fcntl(fd, F_SETLKW, &wrlock);

		printf("record %d is locked.Press ENTER to unlock.", recordid);
		getchar();
		getchar();

		wrlock.l_type = F_ULOCK;

		fcntl(fd, F_SETLKW, &wrlock);
		printf("record %d unlocked\n", recordid);
	}
}
/*
============================================================================
output:
ab@ab:~$ cc 18a.c
ab@ab:~$ ./a.out
enter record to be locked: 2
locking...record 2 is locked.Press ENTER to unlock.
record 2 unlocked
============================================================================
*/
