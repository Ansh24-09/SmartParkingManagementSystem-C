#include <stdio.h>
#include <stdlib.h>
#include "parking.h"

struct Slot* addSlot(struct Slot *head, int id, int time) {
    struct Slot *newSlot = (struct Slot*)malloc(sizeof(struct Slot));
    newSlot->id = id;
    newSlot->time = time;
    newSlot->next = head;
    printf("Slot %d booked for %d hrs.\n", id, time);
    return newSlot;
}

void showSlots(struct Slot *head) {
    struct Slot *p = head;
    printf("\n-- Active Slots --\n");
    while (p != NULL) {
        printf("Slot %d | Time: %d hrs\n", p->id, p->time);
        p = p->next;
    }
}

void saveSlots(struct Slot *head) {
    FILE *f = fopen("slots.txt", "w");
    struct Slot *p = head;
    while (p != NULL) {
        fprintf(f, "Slot %d - %d hrs\n", p->id, p->time);
        p = p->next;
    }
    fclose(f);
}
