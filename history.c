#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_LENGTH 1000

void readHistory() {
    FILE *file = fopen("History.txt", "r");
    char line[MAX_LENGTH];

    if (file == NULL) {
        printf("File tidak ditemukan.\n");
        return;
    }

    while (fgets(line, MAX_LENGTH, file) != NULL) {
        printf("\t\t%s", line);
    }
	getch();
    fclose(file);
}

void writeHistory(char *entry) {
    FILE *file = fopen("History.txt", "a");

    if (file == NULL) {
        printf("File tidak ditemukan.\n");
        return;
    }

    fprintf(file, "%s", entry);

    fclose(file);
}