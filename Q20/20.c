/*
============================================================================
Name : 20.c
Author : Abhishek Mandal
Description : Find out the priority of your running program. Modify the priority with nice command.
Date : 1th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/resource.h>
int main(){

	printf("pid is : %d\n", getpid());

	while(1){
		int p = getpriority(PRIO_PROCESS, 0);
		printf("priority value: %d\n", p);
		sleep(20);
	}
	return 0;
}

/*
============================================================================
output:
ab@ab:~$ gcc 20.c
ab@ab:~$ ./a.out
process id: 10552
current nice value: 0
ab@ab:~$ nice -n 10 ./a.out
process id: 10584
current nice value: 10
ab@ab:~$ sudo nice -n -5 ./a.out
[sudo] password for ab: 
process id: 10635
current nice value: -5
============================================================================
*/	
