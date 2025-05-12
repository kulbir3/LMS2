# include <stdio.h>
# include "myfunctions.h"

    void return_book(){
        FILE *ptr = fopen("Book.txt","a");
        FILE *iss = fopen("issue_log.txt","r");
        FILE *iss1 = fopen("temp.txt","w");
        if(ptr == NULL|| iss == NULL|| iss1 == NULL){
            printf("Error opening file!\n");
            return;
        }
        printf("Enter book id: ");
        scanf("%d", &b.id);

        printf("Enter book name: ");
        getchar();
        scanf("%[^\n]",b.name);
         
        printf("Enter Author name: ");
        getchar();
        scanf("%[^\n]",b.author);

        printf("Enter Genre: ");
        getchar();
        scanf("%[^\n]",b.genre);

        fprintf(ptr,"%d %s %s %s",b.id,b.name,b.author,b.genre);

        int id1;
        int found = 0;
        printf("Enter ID to return book: ");
        scanf("%d",&id1);
    
        while(!feof(iss)){
            fscanf(iss,"%d %d %s",&u.id,&b.id,b.name);
            if(id1 != b.id){
                printf("Book return!\n");
                fprintf(iss1,"%d %d %s\n",u.id,b.id,b.name);
                found = 1;
            }
        }


        fclose(ptr);
        fclose(iss);
        fclose(iss1);

        remove("issue_log.txt");
        rename("temp.txt","issue_log.txt");
    }