/*
============================================================================
Name : 28.c
Author : Abhishek Mandal
Description :Write a program to get maximum and minimum real time priority.
Date: 6th Sep, 2025.
============================================================================
*/
#include <stdio.h>
#include <sched.h>
int main()
{
    printf("Maximum priority for FIFO scheduling is %d and minimum priority is %d\n", sched_get_priority_max(SCHED_FIFO), sched_get_priority_min(SCHED_FIFO));
    printf("Maximum priority for RR scheduling is %d and minimum priority is %d\n", sched_get_priority_max(SCHED_RR), sched_get_priority_min(SCHED_RR));
    printf("Maximum priority for other scheduling priority is %d and minimum priority is %d\n", sched_get_priority_max(SCHED_OTHER), sched_get_priority_min(SCHED_OTHER));
    return 0;
}
/*
============================================================================
output:
ab@ab:~$ cc 28.c
ab@ab:~$ ./a.out
Maximum priority for FIFO scheduling is 99 and minimum priority is 1
Maximum priority for RR scheduling is 99 and minimum priority is 1
Maximum priority for other scheduling priority is 0 and minimum priority is 0
============================================================================
*/
