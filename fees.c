#include <stdio.h>
#include "fees.h"

long calcDuration(long start, long end) {
    return (end - start) / 60; 
}

void recordTransaction(struct Park *p) {
    long duration = calcDuration(p->startTime, p->endTime);
    int cost = duration * 2;

    FILE *f = fopen("transactions.txt", "a");
    if (!f) {
        printf("Error opening transactions file!\n");
        return;
    }

    fprintf(f, "%d %s %s %ld %ld %ld %d\n",
            p->id, p->slotName, p->plate, p->startTime, p->endTime, duration, cost);
    fclose(f);
}
