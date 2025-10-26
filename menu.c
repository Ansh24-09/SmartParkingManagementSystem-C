#include <stdio.h>
#include "auth.h"
#include "fees.h"
#include "record.h"
#include "session.h"
#include "parking.h"
#include "payment.h"
#include "admin.h"

void showMainMenu() {
    struct Slot *head = NULL;
    int ch, id, hrs, fee, logged = 0, opt, ad;

    printf("\n--- Smart Parking System ---\n");
    printf("1. Login\n2. Register\n3. Admin Login\nChoose: ");
    scanf("%d", &opt);

    if (opt == 2) {
        registerUser();
    } else if (opt == 3) {
        ad = adminLogin();
        if (ad) adminMenu();
        return;
    }

    logged = login();
    if (!logged) return;

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
                scanf("%d", &hrs);
                fee = calcFee(hrs);
                head = addSlot(head, id, hrs);
                addRecord(id, hrs, fee);
                saveSession("Vehicle parked successfully.");
                saveSlots(head);
                makePayment(fee);
                printf("Parking confirmed.\n");
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
                printf("Exiting user menu...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 5);
}
