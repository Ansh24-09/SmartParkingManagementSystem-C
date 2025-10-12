#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "auth.h"
#include "parking.h"
#include "fees.h"
#include "record.h"
#include "session.h"

int main() {
    struct Slot *head = NULL;
    int choice, hours;
    char userType[10]; // optional for login type
    printf("--- Smart Parking System ---\n");
    printf("1. Login\n2. Register\nChoose: ");
    scanf("%d", &choice);

    if (choice == 2) registerUser();

    if (!login(userType)) return 0;
    do {
        printf("\n--- Parking Menu ---\n");
        printf("1. Park Vehicle\n2. View Slots\n3. View Records\n4. View Sessions\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { // Park Vehicle
                struct Park transaction;
                int freeSlot = getNextFreeSlot(head);
                if (freeSlot == -1) {
                    printf("Parking full! No free slots.\n");
                    break;
                }

                transaction.id = freeSlot;
                printf("Enter parking hours: ");
                scanf("%d", &hours);
                printf("Enter vehicle plate: ");
                scanf("%s", transaction.plate);
                snprintf(transaction.slotName, sizeof(transaction.slotName), "SLOT%d", freeSlot);
                transaction.startTime = time(NULL);
                transaction.endTime = transaction.startTime + hours * 3600;

                head = addSlot(head, freeSlot, hours);
                addRecord(freeSlot, hours, hours * 20);  // optional
                recordTransaction(&transaction);
                saveSession("New parking session added.");
                saveSlots(head);

                long fee = calcDuration(transaction.startTime, transaction.endTime) * 2;
                printf("Allocated Slot: %d\n", freeSlot);
                printf("Fee: ₹%ld\n", fee);
                break;
            }

            case 2: 
                showSlots(head);
                break;

            case 3: 
                viewRecords();
                break;

            case 4: 
                showSession();
                break;

            case 5: 
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
