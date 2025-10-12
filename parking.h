#ifndef PARKING_H
#define PARKING_H

#define MAX_SLOTS 10

struct Slot {
    int id;
    int hours;
    struct Slot *next;
};

struct Park {
    int id;
    char slotName[10];
    char plate[20];
    long startTime;
    long endTime;
};

struct Slot* addSlot(struct Slot *head, int id, int hours);
void showSlots(struct Slot *head);
void saveSlots(struct Slot *head);
int getNextFreeSlot(struct Slot *head);

#endif
