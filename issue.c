#include <stdio.h>
#include <string.h>
#include "myfunctions.h"

void issue_book() {
    char buffer[50];
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
    FILE *temp = fopen("temp.txt","w");
    FILE *log = fopen("issue_log.txt", "a");
    FILE *log1 = fopen("history_log.txt","a");

    if (iss == NULL || temp == NULL || log == NULL || log1 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int found = 0;
    get_time(buffer, sizeof(buffer));
    while (fscanf(iss, "%d %s %s %s %d", &b.id, b.name, b.author, b.genre, &b.cpy) == 5) {
        if (b.id == b_id && b.cpy > 0){
            found = 1;
            b.cpy--;
            fprintf(temp, "%d %s %s %s %d\n",b.id, b.name, b.author, b.genre, b.cpy);
            fprintf(log, "%d %s %s %s %d\n",b.id, b.name, b.author, b.genre, u.id);
            fprintf(log1, "User id: %d Book: %s Issued time: %s\n",u.id, b.name, buffer);
            printf("Book issue successfully: %s\n", b.name);
        }else{
            fprintf(temp, "%d %s %s %s %d\n",b.id, b.name, b.author, b.genre, b.cpy);
        }
    }

    if (!found) {
        printf("Book not found or already issued.\n");
    }

    fclose(iss);
    fclose(temp);
    fclose(log);
    fclose(log1);
    
    remove("Book.txt");
    rename("temp.txt", "Book.txt");
}
