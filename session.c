#include <stdio.h>
#include "session.h"

void saveSession(char *msg) {
    FILE *f = fopen("session.txt", "a");
    fprintf(f, "%s\n", msg);   
    fclose(f);
}

void showSession() {
    char line[100];
    FILE *f = fopen("session.txt", "r");
    if (!f) {
        printf("No sessions found!\n");
        return;
    }
    printf("\n-- Session Log --\n");
    while (fgets(line, sizeof(line), f))
        printf("%s", line);
    fclose(f);
}
