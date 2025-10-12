#ifndef PARKING_H
#define PARKING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Park {
    int id;
    char slot[10];
    char plate[15];
    long start;
    long end;
    struct Park *next; // linked list pointer
} Park;

typedef struct User {
    char name[20];
    char pass[20];
} User;

// function declarations
int login();
void addSession(Park **head);
void endSession(Park **head);
void displaySessions(Park *head);
void saveSessions(Park *head);
void recordTransaction(Park *p);
long calcDuration(long start, long end);

#endif
