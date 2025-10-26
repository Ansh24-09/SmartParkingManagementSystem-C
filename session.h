#ifndef SESSION_H
#define SESSION_H

typedef struct Node {
    int slot;
    char vehicle[20];
    char user[20];
    long inTime;
    struct Node *next;
} Node;

extern Node *head;

void addSession(int slot, char *vehicle, char *user, long inTime);
void endSession(int slot);
void showSessions();
Node* findSessionBySlot(int slot); // 🔍 new DSA-based search function

#endif
