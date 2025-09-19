/*
============================================================================
Name : 13.c
Author : Abhishek Mandal
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date : 1th Sep, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/select.h>
int main(){
    fd_set readfds;
    struct timeval timeout;
    int retval;

    FD_ZERO(&readfds);

    FD_SET(STDIN_FILENO, &readfds);


    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    printf("waitig for input...\n");

    retval = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if(retval == -1){
	    perror("select error");

    }
    else if(retval == 0){
	    printf("no data entered within 10 seconds: Timeout\n");
    }
    else{
	    if(FD_ISSET(STDIN_FILENO, &readfds)){
		    printf("data is available: reading now\n");
		    char buffer[100];
		    int n = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
		    if(n > 0){
			    buffer[n] = '\0';
			    printf("data entered: %s\n", buffer);
		    }
	    }
    }
    return 0;
}

/*
============================================================================
output:
ab@ab:~$ gcc 13.c
ab@ab:~$ ./a.out
waitig for input...
its mee!
data is available: reading now
data entered: its mee!
============================================================================
*/	
