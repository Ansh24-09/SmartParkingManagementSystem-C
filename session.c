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
        int l = 2*i, r = 2*i+1, s = i;
        if (l <= *n && h[l].duration < h[s].duration) s = l;
        if (r <= *n && h[r].duration < h[s].duration) s = r;
        if (s == i) break;
        swap(&h[i], &h[s]);
        i = s;
    }
    return slotNo;
}

// ---------- QUEUE ----------
void enqueue(Queue q[], int *front, int *rear, int id, char plate[], int dur) {
    if (*rear == MAX_WAIT - 1) {
        printf("\nQueue full! Cannot add vehicle %s\n", plate);
        return;
    }
    (*rear)++;
    q[*rear].id = id;
    strcpy(q[*rear].plate, plate);
    q[*rear].duration = dur;
    printf("Added to waiting queue: %s\n", plate);
}

int isQueueEmpty(int front, int rear) {
    return (front > rear);
}

void dequeueAndAssign(Park **head, Queue q[], int *front, int *rear, Heap heap[], int *heapCount) {
    if (isQueueEmpty(*front, *rear)) return;
    int slot = extractMinSlot(heap, heapCount);
    if (slot == -1) return;

    Queue v = q[*front];
    (*front)++;

    Park *n = (Park*)malloc(sizeof(Park));
    n->id = v.id;
    n->duration = v.duration;
    sprintf(n->slot, "S%d", slot);
    strcpy(n->plate, v.plate);
    n->start = time(NULL);
    n->next = *head;
    *head = n;

    printf("\nVehicle from queue assigned slot %s\n", n->slot);
}

// ---------- SESSIONS ----------
void addSession(Park **head, Heap heap[], int *heapCount, Queue q[], int *front, int *rear) {
    int id, dur;
    char plate[15];
    printf("\nEnter Vehicle ID: ");
    scanf("%d", &id);
    printf("Enter Vehicle Plate: ");
    scanf("%s", plate);
    printf("Enter expected duration (in minutes): ");
    scanf("%d", &dur);

    if (*heapCount >= MAX_SLOTS) {
        enqueue(q, front, rear, id, plate, dur);
        return;
    }

    insertSlot(heap, heapCount, *heapCount + 1, dur);
    int slot = extractMinSlot(heap, heapCount);

    Park *n = (Park*)malloc(sizeof(Park));
    n->id = id;
    n->duration = dur;
    sprintf(n->slot, "S%d", slot);
    strcpy(n->plate, plate);
    n->start = time(NULL);
    n->next = *head;
    *head = n;

    printf("Assigned Slot: %s\n", n->slot);
}

void endSession(Park **head, Queue q[], int *front, int *rear, Heap heap[], int *heapCount) {
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
    insertSlot(heap, heapCount, atoi(t->slot + 1), t->duration);
    free(t);

    dequeueAndAssign(head, q, front, rear, heap, heapCount);
}

void displaySessions(Park *head) {
    printf("\nActive Vehicles:\n");
    printf("ID\tPlate\tSlot\tDuration(min)\n");
    while (head) {
        printf("%d\t%s\t%s\t%d\n", head->id, head->plate, head->slot, head->duration);
        head = head->next;
    }
}

// ---------- TRANSACTIONS ----------
void recordTransaction(Park *p) {
    FILE *fp = fopen("transactions.txt", "a");
    if (!fp) return;
    fprintf(fp, "ID:%d Plate:%s Duration:%d Slot:%s\n", p->id, p->plate, p->duration, p->slot);
    fclose(fp);
}

void binarySearch(Park *head, int id) {
    Park *arr[50];
    int n = 0;
    while (head) {
        arr[n++] = head;
        head = head->next;
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i]->id > arr[j]->id) {
                Park *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

    int low = 0, high = n - 1, mid, found = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid]->id == id) {
            printf("\nVehicle Found: %s in Slot %s\n", arr[mid]->plate, arr[mid]->slot);
            found = 1;
            break;
        } else if (arr[mid]->id > id)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (!found) printf("\nVehicle ID not found!\n");
}
