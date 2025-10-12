#ifndef PARKING_H
#define PARKING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SLOTS 5     // small number to test queue
#define MAX_WAIT 10

typedef struct Park {
    int id;
    char plate[15];
    char slot[10];
    int duration;
    long start;
    long end;
    struct Park *next;
} Park;

typedef struct Heap {
    int slotNo;
    int duration;
} Heap;

typedef struct Queue {
    int id;
    char plate[15];
    int duration;
} Queue;

void addSession(Park **head, Heap heap[], int *heapCount, Queue q[], int *front, int *rear);
void endSession(Park **head, Queue q[], int *front, int *rear, Heap heap[], int *heapCount);
void displaySessions(Park *head);
void recordTransaction(Park *p);
void enqueue(Queue q[], int *front, int *rear, int id, char plate[], int dur);
void dequeueAndAssign(Park **head, Queue q[], int *front, int *rear, Heap heap[], int *heapCount);
int isQueueEmpty(int front, int rear);
void insertSlot(Heap h[], int *n, int slotNo, int duration);
int extractMinSlot(Heap h[], int *n);
void binarySearch(Park *head, int id);

#endif
