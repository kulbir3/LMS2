# include <stdio.h>
# include <string.h>
# include "myfunctions.h"

void issue_book() {
    char buffer[50];
    char user_id[20];
    printf("Enter user id: ");
    getchar();
    scanf("%[^\n]",user_id);

    if (!user_exists(user_id)) {
        printf("User not found.\n");
        return;
    }
   
    FILE *iss, *temp, *log, *log1;
    char b_id[20];
    char buf[256];
    printf("\nEnter book id to issue: ");
    getchar();
    scanf("%[^\n]",b_id);

    iss = fopen("Book.txt", "r");
    temp = fopen("temp.txt","w");
    log = fopen("issue_log.txt", "a");
    log1 = fopen("history_log.txt","a");

    if (iss == NULL || temp == NULL || log == NULL || log1 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int found = 0;
    get_time(buffer, sizeof(buffer));

       while (fgets(buf, sizeof(buf), iss)){
       if(sscanf(buf, "Id:%[^|]|Name:%[^|]|Author:%[^|]|Genre:%[^|]|Copies:%d", b.id, b.name, b.author, b.genre, &b.cpy) == 5){
        if (strcmp(b.id, b_id)==0 && b.cpy > 0){

            found = 1;
            b.cpy--;
            fprintf(temp, "Id:%s|Name:%s|Author:%s|Genre:%s|Copies:%d\n",b.id, b.name, b.author, b.genre, b.cpy);
            fprintf(log, "Id:%s|Name:%s|Author:%s|Genre:%s|UId:%s\n",b.id, b.name, b.author, b.genre, u.id);
            fprintf(log1, "User id: %s Book: %s Issued time: %s\n",u.id, b.name, buffer);
            printf("Book issue successfully: %s\n", b.name);
         }else{
            fprintf(temp, "Id:%s|Name:%s|Author:%s|Genre:%s|Copies:%d\n",b.id, b.name, b.author, b.genre, b.cpy);
           }
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
