# include <stdio.h>
# include "myfunctions.h"

    void display_info(){
        char line[1024];
        char choice;
        printf("Enter b/B to display books or u/U to display users: ");
        scanf(" %c",&choice);

        if(choice == 'b' || choice == 'B'){
            FILE *ptr = fopen("Book.txt","r");
            if(ptr == NULL){
                printf("Error opening file!");
                return;
            }
            while(fgets(line,sizeof(line),ptr) != NULL){
                 printf("%s",line);
            }
            fclose(ptr);
        }
        else if(choice == 'u' || choice == 'U'){
                FILE *ptr1 = fopen("user.txt","r");
                if(ptr1 == NULL){
                    printf("Error opening file!");
                    return;
                }
                while(fgets(line,sizeof(line),ptr1) != NULL){
                    printf("%s",line);
                }
                fclose(ptr1);
             }
             else{
                printf("Invalid choice!");
             }
}
