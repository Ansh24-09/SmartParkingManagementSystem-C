#include <stdio.h>
#include <string.h>
#include "admin.h"
#include "record.h"
#include "session.h"

int adminLogin() {
    char user[20], pass[20];
    printf("\n--- Admin Login ---\n");
    printf("Enter username: ");
    scanf("%s", user);
    printf("Enter password: ");
    scanf("%s", pass);

    if (strcmp(user, "admin") == 0 && strcmp(pass, "1234") == 0) {
        printf("Admin login successful!\n");
        return 1;
    } else {
        printf("Invalid admin credentials!\n");
        return 0;
    }
}

void adminMenu() {
    int ch;
    do {
        printf("\n--- Admin Panel ---\n");
        printf("1. View All Records\n2. View Sessions\n3. Exit Admin\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                viewRecords();
                break;
            case 2:
                showSession();
                break;
            case 3:
                printf("Exiting admin panel...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 3);
}
