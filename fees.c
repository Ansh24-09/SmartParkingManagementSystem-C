#include "parking.h"

long calcDuration(long start, long end) {
    return (end - start) / 60; // duration in minutes
}

void recordTransaction(Park *p) {
    long dur = calcDuration(p->start, p->end);
    int cost = dur * 2; // ₹2 per minute
    FILE *f = fopen("transactions.txt", "a");
    fprintf(f, "%d %s %s %ld %ld %ld %d\n", p->id, p->slot, p->plate, p->start, p->end, dur, cost);
    fclose(f);
}
