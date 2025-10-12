#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parking.h"

struct Slot* addSlot(struct Slot *head, int id, int hours) {
    struct Slot *newSlot = (struct Slot*)malloc(sizeof(struct Slot));
    newSlot->id = id;
    newSlot->hours = hours;
    newSlot->next = head;
    printf("Slot %d booked for %d hours.\n", id, hours);
    return newSlot;
}

void showSlots(struct Slot *head) {
    struct Slot *p = head;
    printf("\n-- Active Slots --\n");
    while (p) {
        printf("Slot %d | Hours: %d\n", p->id, p->hours);
        p = p->next;
    }
}

void saveSlots(struct Slot *head) {
    FILE *f = fopen("slots.txt", "w");
    struct Slot *p = head;
    while (p) {
        fprintf(f, "Slot %d - %d hrs\n", p->id, p->hours);
        p = p->next;
    }
    fclose(f);
}

int getNextFreeSlot(struct Slot *head) {
    int occupied[MAX_SLOTS+1] = {0}; // slot 1..MAX_SLOTS
    struct Slot *p = head;
    while (p) {
        if (p->id >= 1 && p->id <= MAX_SLOTS)
            occupied[p->id] = 1;
        p = p->next;
    }

    for (int i = 1; i <= MAX_SLOTS; i++) {
        if (!occupied[i]) return i; // first free slot
    }

    return -1; // no free slot
}
