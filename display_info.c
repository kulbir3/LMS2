# include <stdio.h>
# include "myfunctions.h"

    void display_info(){
        char choice, buf[256];
        printf("Enter b/B to display books or u/U to display users: ");
        scanf(" %c",&choice);

        if(choice == 'b' || choice == 'B'){
            FILE *ptr = fopen("Book.txt","r");
            if(ptr == NULL){
                printf("Error opening file!");
                return;
            }
            while(fgets(buf, sizeof(buf), ptr)){
               if(sscanf(buf,"%d|%[^|]|%[^|]|%[^|]|%d",&b.id, b.name ,b.author, b.genre, &b.cpy) != EOF){
                printf("ID: %d Name: %s Author: %s Genre: %s Copies: %d\n",b.id, b.name, b.author, b.genre, b.cpy);
               }
            }
            fclose(ptr);
        }
        else if(choice == 'u' || choice == 'U'){
                FILE *ptr1 = fopen("user.txt","r");
                if(ptr1 == NULL){
                    printf("Error opening file!");
                    return;
                }
                while(fscanf(ptr1,"%d %s %s %d",&u.id,u.user_name,u.email,&u.number) != EOF){  
                    printf("ID: %d Name: %s Email: %s Number: %d\n",u.id,u.user_name,u.email,u.number);
               
                }
                fclose(ptr1);
             }
             else{
                printf("Invalid choice!");
             }
}
