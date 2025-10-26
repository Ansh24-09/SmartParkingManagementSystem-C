#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "session.h"

Node *head = NULL;

void addSession(int slot, char *vehicle, char *user, long inTime) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->slot = slot;
    strcpy(newNode->vehicle, vehicle);
    strcpy(newNode->user, user);
    newNode->inTime = inTime;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
void endSession(int slot) {
    Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->slot != slot) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nNo session found for slot %d.\n", slot);
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("\nSlot %d session ended.\n", slot);
}
void showSessions() {
    Node *temp = head;
    if (temp == NULL) {
        printf("\nNo active sessions.\n");
        return;
    }

    printf("\nActive Parking Sessions:\n");
    while (temp != NULL) {
        printf("Slot: %d | Vehicle: %s | User: %s | In-Time: %ld\n",
               temp->slot, temp->vehicle, temp->user, temp->inTime);
        temp = temp->next;
    }
}
Node* findSessionBySlot(int slot) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->slot == slot)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
