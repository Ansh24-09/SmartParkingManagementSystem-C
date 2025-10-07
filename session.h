#ifndef SESSION_H
#define SESSION_H

typedef struct {
    int id;
    char slot[10];
    char plate[15];
    long start;
    long end;
} Park;

void checkIn();
void checkOut();

#endif
