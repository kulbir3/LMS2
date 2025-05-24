#include <stdio.h>
#include "myfunctions.h"

void return_book() {
    FILE *iss = fopen("issue_log.txt", "r");
    FILE *ret = fopen("Book.txt", "a");
    FILE *temp = fopen("temp.txt", "w");
    FILE *log = fopen("history_log.txt","a");

    if (iss == NULL || ret == NULL || temp == NULL) {
        printf("Error opening file");
        return;
    }

    int id1, uid, found = 0;
    printf("Enter book ID & Uid to return: ");
    scanf("%d %d", &id1,&uid);

    char buffer[50];
    get_time(buffer, sizeof(buffer));

    while (fscanf(iss, "%d %s %s %s %d", &b.id, b.name, b.author, b.genre, &u.id) == 5) {
        if (id1 == b.id && uid == u.id) {
            b.cpy++;
            fprintf(ret, "%d %s %s %s %d\n", b.id, b.name, b.author, b.genre, b.cpy);
            fprintf(log, "User id: %d Book: %s Return time: %s",u.id, b.name, buffer);
            found = 1;
        } else {
            fprintf(temp, "%d %s %s %s %d \n", b.id, b.name, b.author, b.genre, u.id);
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
        
