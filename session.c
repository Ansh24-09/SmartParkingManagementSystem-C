#include "parking.h"

void addSession(Park **head) {
    Park *n = (Park *)malloc(sizeof(Park));
    printf("\nEnter vehicle ID: ");
    scanf("%d", &n->id);
    printf("Enter slot number: ");
    scanf("%s", n->slot);
    printf("Enter vehicle plate: ");
    scanf("%s", n->plate);
    n->start = time(NULL);
    n->end = 0;
    n->next = *head;
    *head = n;
    printf("Vehicle parked successfully.\n");
}

void endSession(Park **head) {
    int id;
    printf("\nEnter vehicle ID to exit: ");
    scanf("%d", &id);

    Park *temp = *head, *prev = NULL;
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Vehicle not found.\n");
        return;
    }

    temp->end = time(NULL);
    recordTransaction(temp);

    if (prev == NULL) *head = temp->next;
    else prev->next = temp->next;

    free(temp);
    printf("Vehicle exited and transaction saved.\n");
}

void displaySessions(Park *head) {
    Park *p = head;
    printf("\nActive Sessions:\n");
    printf("ID\tSlot\tPlate\tStart Time\n");
    while (p) {
        printf("%d\t%s\t%s\t%ld\n", p->id, p->slot, p->plate, p->start);
        p = p->next;
    }
}

void saveSessions(Park *head) {
    FILE *f = fopen("sessions.txt", "w");
    Park *p = head;
    while (p) {
        fprintf(f, "%d %s %s %ld %ld\n", p->id, p->slot, p->plate, p->start, p->end);
        p = p->next;
    }
    fclose(f);
}
