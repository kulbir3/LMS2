#include <stdio.h>
#include "myfunctions.h"

void return_book() {
    FILE *iss = fopen("issue_log.txt", "r");
    FILE *ret = fopen("Book.txt", "a");
    FILE *temp = fopen("temp.txt", "w");
    FILE *log = fopen("history_log.txt","a");

    if (iss == NULL || ret == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int id1, found = 0;
    printf("Enter book ID to return: ");
    scanf("%d", &id1);

    char buffer[50];
    get_time(buffer, sizeof(buffer));

    while (fscanf(iss, "%d %s %s %s %s", &b.id, b.name, b.author, b.genre,u.email) == 5) {
        if (id1 == b.id) {
            fprintf(ret, "%d %s %s %s\n", b.id, b.name, b.author, b.genre);
            fprintf(log,"User id: %d Book: %s Return time: %s",u.id, b.name, buffer);
            found = 1;
        } else {
            fprintf(temp, "%d %s %s %s %s\n", b.id, b.name, b.author, b.genre, u.email);
        }
    }

    if (found) {
        printf("Book returned successfully!\n");
    } else {
        printf("Book ID %d not found in issue_log.\n", id1);
    }

    fclose(iss);
    fclose(ret);
    fclose(temp);
    fclose(log);

    remove("issue_log.txt");
    rename("temp.txt", "issue_log.txt");
}
