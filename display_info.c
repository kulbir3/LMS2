# include <stdio.h>
# include "myfunctions.h"

    void display_info(){
        char choice;
        printf("Enter b/B to display books or u/U to display users: ");
        scanf(" %c",&choice);

        if(choice == 'b' || choice == 'B'){
            FILE *ptr = fopen("Book.txt","r");
            if(ptr == NULL){
                printf("Error opening file!");
                return;
            }
            while(fscanf(ptr,"%d %s %s %s",&b.id,b.name,b.author,b.genre) != EOF){
                printf("ID: %d Name: %s Author: %s Genre: %s\n",b.id,b.name,b.author,b.genre);
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
