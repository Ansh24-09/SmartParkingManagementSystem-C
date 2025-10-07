#include <stdio.h>
#include "auth.h"
#include "session.h"

int main() {
    int ch;
    printf("==== SMART PARKING SYSTEM ====\n");
    while (1) {
        printf("\n1. Register\n2. Login\n3. Check-In\n4. Check-Out\n5. Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: regUser(); break;
            case 2: loginUser(); break;
            case 3: checkIn(); break;
            case 4: checkOut(); break;
            case 5: printf("Goodbye!\n"); return 0;
            default: printf("Invalid option!\n");
        }
    }
    return 0;
}
