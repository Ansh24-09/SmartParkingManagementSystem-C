#include <stdio.h>
#include <time.h>
#include <string.h>
#include "session.h"
#include "fee.h"
#include "record.h"

void checkIn() {
    Park p;
    FILE *fp = fopen("sessions.txt", "a");
    if (!fp) return;

    printf("Enter slot ID: ");
    scanf("%s", p.slot);
    printf("Enter vehicle number: ");
    scanf("%s", p.plate);
    p.start = time(NULL);
    p.end = 0;

    fprintf(fp, "%s %s %ld %ld\n", p.slot, p.plate, p.start, p.end);
    fclose(fp);
    printf("Check-in Done!\n");
}

void checkOut() {
    Park p;
    char plate[15];
    long now = time(NULL);
    int found = 0;
    FILE *fp = fopen("sessions.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) return;

    printf("Enter vehicle number: ");
    scanf("%s", plate);

    while (fscanf(fp, "%s %s %ld %ld", p.slot, p.plate, &p.start, &p.end) != EOF) {
        if (strcmp(p.plate, plate) == 0 && p.end == 0) {
            p.end = now;
            found = 1;
            double fee = calcFee(p.start, p.end);
            printf("Total Fee: ₹%.2f\n", fee);
            saveRecord(p.slot, p.plate, fee);
        }
        fprintf(temp, "%s %s %ld %ld\n", p.slot, p.plate, p.start, p.end);
    }
    fclose(fp);
    fclose(temp);
    remove("sessions.txt");
    rename("temp.txt", "sessions.txt");

    if (!found) printf("Vehicle not found or already checked out.\n");
    else printf("Check-out Complete!\n");
}
