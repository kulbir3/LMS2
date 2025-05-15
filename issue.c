#include <stdio.h>
#include <string.h>
#include "myfunctions.h"

void issue_book() {
    int user_id;
    printf("Enter user id: ");
    scanf("%d", &user_id);

    if (!user_exists(user_id)) {
        printf("User not found.\n");
        return;
    }

    int b_id;
    printf("\nEnter book id to issue: ");
    scanf("%d", &b_id);

    FILE *iss = fopen("Book.txt", "r");
    FILE *iss1 = fopen("temp.txt", "w");
    FILE *log = fopen("issue_log.txt", "a");

    if (iss == NULL || iss1 == NULL || log == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int found = 0;

    while (fscanf(iss, "%d %s %s %s", &b.id, b.name, b.author, b.genre) == 4) {
        if (b.id == b_id) {
            found = 1;
            fprintf(log,"%d %s %s %s %s\n",b.id,b.name,b.author,b.genre,u.email);
            printf("Book issue successfully: %s\n", b.name);
        } else {
            fprintf(iss1, "%d %s %s %s\n", b.id, b.name, b.author, b.genre);
        }
    }

    if (!found) {
        printf("Book not found or already issue.\n");
    }

    fclose(iss);
    fclose(iss1);
    fclose(log);

    remove("Book.txt");
    rename("temp.txt", "Book.txt");
}
