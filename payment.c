#include <stdio.h>
#include "payment.h"

void makePayment(int amt) {
    int mode;
    printf("\n--- Payment ---\n");
    printf("Amount: ₹%d\n", amt);
    printf("Choose method: 1. Cash  2. UPI  3. Card\n");
    scanf("%d", &mode);

    switch (mode) {
        case 1:
            printf("Payment done by Cash.\n");
            break;
        case 2:
            printf("Payment done by UPI.\n");
            break;
        case 3:
            printf("Payment done by Card.\n");
            break;
        default:
            printf("Invalid method. Defaulting to Cash.\n");
    }
    printf("Payment successful!\n");
}
