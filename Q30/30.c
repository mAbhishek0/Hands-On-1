/*
============================================================================
Name : 30.c
Author : Abhishek Mandal
Description : Write a program to run a script at a specific time using a
Daemon process.
Date : 6th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
int main(){
	int pid = fork();

	if(pid < 0){
		perror("fork failed");
		exit(1);
	}

	if(pid > 0){
		printf("parent exits now.\n");
		exit(0);
	}

	setsid();
	chdir("/");
	close(0);
	close(1);
	close(2);
	int hour = 18;
	int min = 11;
	const char *script = "/home/ab/script.sh";

	while(1){
		time_t now = time(NULL);
		struct tm *t = localtime(&now);
			
		//exit it time is greater than time to run script
		if(t->tm_hour > hour || t->tm_min > min){
			system("echo 'current time is higher than time specified' >> /tmp/daemon_log.txt");
			exit(0);}

		if(t->tm_hour == hour && t->tm_min == min){
			system(script);
			sleep(60);
		}
		else{
			sleep(10);
		}
	}
	return 0;
}
/*
============================================================================
output:
ab@ab:~$ cc 30.c
ab@ab:~$ ./a.out
parent exits now.
ab@ab:~$ cat /tmp/script_log.txt

Script executed at: Sat Sep  6 06:11:03 PM IST 2025
============================================================================
*/