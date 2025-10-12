#include <stdio.h>
#include <string.h>
#include "auth.h"

int login() {
    char user[20], pass[20], u[20], p[20];
    int found = 0;

    FILE *f = fopen("users.txt", "r");
    if (!f) {
        printf("No users registered yet. Please register first.\n");
        return 0;
    }

    printf("Enter username: ");
    scanf("%s", user);
    printf("Enter password: ");
    scanf("%s", pass);

    while (fscanf(f, "%s %s", u, p) != EOF) {
        if (strcmp(user, u) == 0 && strcmp(pass, p) == 0) {
            found = 1;
            break;
        }
    }
    fclose(f);

    if (found) {
        printf("\nLogin successful!\n");
        return 1;
    } else {
        printf("\nInvalid login!\n");
        return 0;
    }
}

void registerUser() {
    char user[20], pass[20];
    FILE *f = fopen("users.txt", "a");

    printf("Enter new username: ");
    scanf("%s", user);
    printf("Enter new password: ");
    scanf("%s", pass);

    fprintf(f, "%s %s\n", user, pass);
    fclose(f);

    printf("\nUser registered successfully!\n");
}
