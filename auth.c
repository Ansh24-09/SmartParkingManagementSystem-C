#include "parking.h"

int login() {
    User u;
    char n[20], p[20];
    FILE *f = fopen("users.txt", "r");
    if (!f) {
        printf("Error: users.txt not found!\n");
        return 0;
    }

    printf("\nUsername: ");
    scanf("%s", n);
    printf("Password: ");
    scanf("%s", p);

    while (fscanf(f, "%s %s", u.name, u.pass) != EOF) {
        if (strcmp(n, u.name) == 0 && strcmp(p, u.pass) == 0) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    printf("Invalid credentials!\n");
    return 0;
}
