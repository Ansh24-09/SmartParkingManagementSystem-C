#include "parking.h"

int main() {
    Park *head = NULL;
    Heap heap[20];
    Queue queue[MAX_WAIT];
    int heapCount = 0, front = 0, rear = -1;
    int choice;

    printf("\n===== SMART PARKING MANAGEMENT SYSTEM (DSA VERSION) =====\n");

    while (1) {
        printf("\n------------------ MENU ------------------\n");
        printf("1. Add Vehicle (Check-In)\n");
        printf("2. End Session (Check-Out)\n");
        printf("3. Display Active Sessions\n");
        printf("4. Search Vehicle by ID (Binary Search)\n");
        printf("5. Exit\n");
        printf("------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSession(&head, heap, &heapCount, queue, &front, &rear);
                break;
            case 2:
                endSession(&head, queue, &front, &rear, heap, &heapCount);
                break;
            case 3:
                displaySessions(head);
                break;
            case 4: {
                int id;
                printf("Enter Vehicle ID to Search: ");
                scanf("%d", &id);
                binarySearch(head, id);
                break;
            }
            case 5:
                printf("\nExiting... Thank you!\n");
                return 0;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
}
