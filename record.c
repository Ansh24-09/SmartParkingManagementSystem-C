#include <stdio.h>
#include "record.h"

void addRecord(int id, int time, int fee) {
    FILE *f = fopen("record.txt", "a");
    fprintf(f, "Slot %d | Time: %d hrs | Fee: %d\n", id, time, fee);
    fclose(f);
}

void viewRecords() {
    char line[100];
    FILE *f = fopen("record.txt", "r");
    if (!f) {
        printf("No records found!\n");
        return;
    }
    printf("\n-- Parking Records --\n");
    while (fgets(line, sizeof(line), f))
        printf("%s", line);
    fclose(f);
}
