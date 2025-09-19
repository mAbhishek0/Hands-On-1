/*
============================================================================
Name : 17a.c
Author : Sameer
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 7th Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {


    int ticketnumber;

    printf("Enter the ticket number: ");
    scanf("%d", &ticketnumber);

    int fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
    
    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    char ticketstr[50];
    snprintf(ticketstr, sizeof(ticketstr)," %d\n", ticketnumber);

    write(fd, ticketstr, strlen(ticketstr));
    
    printf("ticket generated\n");

    close(fd);

    return 0;
}
/*
============================================================================
Output:
ab@ab:~$ cc 17a.c
ab@ab:~$ ./a.out ticket.txt
Enter the ticket number: 43
ticket generated
============================================================================
*/