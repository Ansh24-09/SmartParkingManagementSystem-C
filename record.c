#include <stdio.h>
#include <time.h>
#include "record.h"

void saveRecord(char slot[], char plate[], double amt) {
    FILE *fp = fopen("transactions.txt", "a");
    if (!fp) return;
    time_t now = time(NULL);
    fprintf(fp, "%s %s %.2f %s", slot, plate, amt, ctime(&now));
    fclose(fp);
}
