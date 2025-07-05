# include <stdio.h>
# include <string.h> 
# include "myfunctions.h"

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

    char id1[20], uid[20];
    int found = 0;
    printf("Enter book ID & Uid to return: ");
    getchar();
    scanf("%[^\n] %[^\n]",id1,uid);

    char buffer[50], buf[256];
    get_time(buffer, sizeof(buffer));

    while (fgets(buf, sizeof(buf), iss)){
        if(sscanf(buf, "Id:%[^|]|Name:%[^|]|Author:%[^|]|Genre:%[^|]|UId:%s", b.id, b.name, b.author, b.genre, u.id) == 5){
         if (strcmp(id1,b.id)==0 && strcmp(uid,u.id)==0){
            found = 1;
         } else {
            fprintf(temp, "Id:%s|Name:%s|Author:%s|Genre:%s|UId:%s\n", b.id, b.name, b.author, b.genre, u.id);
         }
     }
 }

  if (found) {
        fprintf(log, "User id: %s Book: %s Return time: %s\n", u.id, b.name, buffer);
        printf("Book named %s returned successfully!\n",b.name);
    } else {
        printf("Book ID %s not found in issue_log.\n", id1);
    }

    while(fgets(buf, sizeof(buf), ret)){
       if(sscanf(buf, "Id:%[^|]|Name:%[^|]|Author:%[^|]|Genre:%[^|]|Copies:%d", b.id, b.name, b.author, b.genre, &b.cpy) == 5){
        if(strcmp(id1, b.id)==0 && found){
          b.cpy++;
       }
        fprintf(ptr, "Id:%s|Name:%s|Author:%s|Genre:%s|Copies:%d\n",b.id, b.name, b.author, b.genre, b.cpy);
     }

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
        
