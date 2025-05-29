#include <stdio.h>
#include "myfunctions.h"

void return_book() {
    FILE *iss = fopen("issue_log.txt", "r");
    FILE *ret = fopen("Book.txt", "r");
    FILE *ptr = fopen("temp_book.txt","w");
    FILE *temp = fopen("temp.txt", "w");
    FILE *log = fopen("history_log.txt","a");

    if (iss == NULL || ptr == NULL || ret == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int id1, uid, found = 0;
    printf("Enter book ID & Uid to return: ");
    scanf("%d %d", &id1,&uid);

    char buffer[50], buf[256];
    get_time(buffer, sizeof(buffer));

    while (fgets(buf, sizeof(buf), iss)){
        if(sscanf(buf, "Id:%d|Name:%[^|]|Author:%[^|]|Genre:%[^|]|UId:%d", &b.id, b.name, b.author, b.genre, &u.id) == 5){
         if (id1 == b.id && uid == u.id){
            found = 1;
         } else {
            fprintf(temp, "Id:%d|Name:%s|Author:%s|Genre:%s|UId:%d\n", b.id, b.name, b.author, b.genre, u.id);
         }
     }
 }
    while(fgets(buf, sizeof(buf), ret)){
       if(sscanf(buf, "Id:%d|Name:%[^|]|Author:%[^|]|Genre:%[^|]|Copies:%d", &b.id, b.name, b.author, b.genre, &b.cpy) == 5){
        if(id1 == b.id && found){
          b.cpy++;
       }
        fprintf(ptr, "Id:%d|Name:%s|Author:%s|Genre:%s|Copies:%d\n",b.id, b.name, b.author, b.genre, b.cpy);
     }

 } 

    if (found) {
        fprintf(log, "User id: %d Book: %s Return time: %s\n", u.id, b.name, buffer);
        printf("Book returned successfully!\n");
    } else {
        printf("Book ID %d not found in issue_log.\n", id1);
    }

    fclose(iss);
    fclose(ret);
    fclose(ptr);
    fclose(temp);
    fclose(log);

    remove("issue_log.txt");
    rename("temp.txt", "issue_log.txt");

    remove("Book.txt");
    rename("temp_book.txt", "Book.txt");
}
        
