#include <stdio.h>
#include <string.h>
#include "auth.h"

int regUser() {
    User u;
    FILE *fp = fopen("users.txt", "a");
    if (!fp) return 0;

    printf("Enter username: ");
    scanf("%s", u.user);
    printf("Enter password: ");
    scanf("%s", u.pass);

    fprintf(fp, "%s %s\n", u.user, u.pass);
    fclose(fp);
    printf("User Registered!\n");
    return 1;
}

int loginUser() {
    User u, t;
    FILE *fp = fopen("users.txt", "r");
    if (!fp) {
        printf("No users found. Please register first.\n");
        return 0;
    }

    printf("Enter username: ");
    scanf("%s", t.user);
    printf("Enter password: ");
    scanf("%s", t.pass);

    while (fscanf(fp, "%s %s", u.user, u.pass) != EOF) {
        if (strcmp(u.user, t.user) == 0 && strcmp(u.pass, t.pass) == 0) {
            fclose(fp);
            printf("Login Success!\n");
            return 1;
        }
    }
    fclose(fp);
    printf("Invalid credentials.\n");
    return 0;
}
