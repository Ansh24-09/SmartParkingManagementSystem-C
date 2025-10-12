#include <stdio.h>
#include <stdlib.h>
#include "auth.h"
#include "fees.h"
#include "record.h"
#include "session.h"
#include "parking.h"

int main() {
    struct Slot *head = NULL;
    int ch, id, time, fee, logged = 0, opt;

    printf("--- Smart Parking System ---\n");
    printf("1. Login\n2. Register\nChoose: ");
    scanf("%d", &opt);

    if (opt == 2) {
        registerUser();
    }

    logged = login();
    if (!logged) return 0;

    do {
        printf("\n--- Parking Menu ---\n");
        printf("1. Park Vehicle\n2. View Slots\n3. View Records\n4. View Sessions\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter slot id: ");
                scanf("%d", &id);
                printf("Enter parking time (hrs): ");
                scanf("%d", &time);
                fee = calcFee(time);
                head = addSlot(head, id, time);
                addRecord(id, time, fee);
                saveSession("New parking session added.");
                saveSlots(head);
                printf("Fee: ₹%d\n", fee);
                break;

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
    } while (ch != 5);

    return 0;
}
