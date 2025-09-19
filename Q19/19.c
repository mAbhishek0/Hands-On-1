/*
============================================================================
Name : 19.c
Author : Abhishek Mandal
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date : 1th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdint.h>
int main(){
    unsigned long long start, end;
	unsigned int low, high;
	asm volatile ("rdtsc" : "=a"(low), "=d"(high));
	start = ((unsigned long long)high << 32) | low;

	getpid();

	asm volatile ("rdtsc" : "=a"(low), "=d"(high));
	end = ((unsigned long long)high << 32) | low;

	printf("time taken by getpid() in cpu cycles: %llu\n", end - start);
	
	return 0;
}
/*
============================================================================
output:
ab@ab:~$ gcc 19.c
ab@ab:~$ ./a.out
time taken by getpid() in cpu cycles: 13079
============================================================================
*/	

