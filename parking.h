#ifndef PARKING_H
#define PARKING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SLOTS 10

typedef struct Park {
    int id;
    char slot[10];
    char plate[15];
    int duration;       // in minutes
    long start;
    long end;
    struct Park *next;
} Park;

typedef struct Heap {
    int slotNo;
    int duration; // duration requested
} Heap;

// Function Declarations
int login();
void addSession(Park **head);
void endSession(Park **head);
void displaySessions(Park *head);
void saveSessions(Park *head);
void recordTransaction(Park *p);
long calcDuration(long start, long end);

// Heap (DSA) functions
void insertSlot(Heap h[], int *n, int slotNo, int duration);
int extractMinSlot(Heap h[], int *n);

#endif
