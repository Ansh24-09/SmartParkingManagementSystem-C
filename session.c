#include "parking.h"

void swap(Heap *a, Heap *b) {
    Heap temp = *a;
    *a = *b;
    *b = temp;
}

void insertSlot(Heap h[], int *n, int slotNo, int duration) {
    (*n)++;
    h[*n].slotNo = slotNo;
    h[*n].duration = duration;

    int i = *n;
    while (i > 1 && h[i].duration < h[i/2].duration) {
        swap(&h[i], &h[i/2]);
        i /= 2;
    }
}

int extractMinSlot(Heap h[], int *n) {
    if (*n == 0) return -1;

    int slotNo = h[1].slotNo;
    h[1] = h[*n];
    (*n)--;

    int i = 1;
    while (1) {
        int l = 2 * i, r = 2 * i + 1, s = i;

        if (l <= *n && h[l].duration < h[s].duration) s = l;
        if (r <= *n && h[r].duration < h[s].duration) s = r;

        if (s == i) break;
        swap(&h[i], &h[s]);
        i = s;
    }
    return slotNo;
}

void addSession(Park **head) {
    static Heap heap[20];
    static int count = 0;

    int id, dur;
    char plate[15];
    printf("\nEnter Vehicle ID: ");
    scanf("%d", &id);
    printf("Enter Vehicle Plate: ");
    scanf("%s", plate);
    printf("Enter expected parking duration (in minutes): ");
    scanf("%d", &dur);

    // Add slot to heap based on duration
    insertSlot(heap, &count, count + 1, dur);
    int slot = extractMinSlot(heap, &count);

    Park *n = (Park *)malloc(sizeof(Park));
    n->id = id;
    n->duration = dur;
    sprintf(n->slot, "S%d", slot);
    strcpy(n->plate, plate);
    n->start = time(NULL);
    n->end = 0;
    n->next = *head;
    *head = n;

    printf("Assigned Slot: %s (based on duration %d mins)\n", n->slot, dur);
}

void endSession(Park **head) {
    int id;
    printf("\nEnter Vehicle ID to exit: ");
    scanf("%d", &id);

    Park *t = *head, *prev = NULL;
    while (t && t->id != id) {
        prev = t;
        t = t->next;
    }

    if (!t) {
        printf("Vehicle not found!\n");
        return;
    }

    t->end = time(NULL);
    recordTransaction(t);

    if (prev) prev->next = t->next;
    else *head = t->next;

    printf("Vehicle %s exited from %s.\n", t->plate, t->slot);
    free(t);
}

void displaySessions(Park *head) {
    printf("\nActive Sessions:\n");
    printf("ID\tPlate\tSlot\tDuration(min)\tStart Time\n");
    while (head) {
        printf("%d\t%s\t%s\t%d\t%ld\n", head->id, head->plate, head->slot, head->duration, head->start);
        head = head->next;
    }
}
