#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen() {
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}
