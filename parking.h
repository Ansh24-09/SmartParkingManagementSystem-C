#ifndef PARKING_H
#define PARKING_H

struct Slot {
    int id;
    int time; // hours parked
    struct Slot *next;
};

struct Slot* addSlot(struct Slot *head, int id, int time);
void showSlots(struct Slot *head);
void saveSlots(struct Slot *head);

#endif
