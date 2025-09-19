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

struct record
{
    int recordid;
    int value;
};

int main(){
	int fd = open("/home/ab/18input.txt", O_RDONLY);
	struct flock rdlock = {F_RDLCK, SEEK_SET, 0, sizeof(struct record), getpid()};
	int recordid;
	printf("enter the record to be read locked: ");
	scanf("%d", &recordid);

	if(recordid > 3){
		printf("invalid record id");
	} else {
	
		printf("locking....\n");
		rdlock.l_start = (recordid - 1) * sizeof(struct record);
		rdlock.l_len = sizeof(struct record);
		fcntl(fd, F_SETLKW, &rdlock);
		
		printf("record %d is now read locked.Press ENTER to unlock.", recordid);
		getchar();
		getchar();
		rdlock.l_type = F_ULOCK;
		fcntl(fd, F_SETLKW, &rdlock);
		printf("record %d is now unlocked\n", recordid);
	}
	return 0;
}
/*
============================================================================
output:
ab@ab:~$ cc 18b.c
ab@ab:~$ ./a.out
enter the record to be read locked: 3
locking....record 3 is now read locked.Press ENTER to unlock.
record 3 is now unlocked
============================================================================
*/