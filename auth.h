#ifndef AUTH_H
#define AUTH_H

typedef struct {
    char user[30];
    char pass[30];
} User;

int regUser();
int loginUser();

#endif
