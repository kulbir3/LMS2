# include <stdio.h>
# include "myfunctions.h"

   void remove_user(){
    FILE *file = fopen("user.txt","r");
    FILE *file1 = fopen("temp.txt","w");
    if(file == NULL || file1 == NULL){
        printf("Error opening file!");
        return;
    }
    int id1;
    int found = 0;
    printf("Enter ID to remove user: ");
    scanf("%d",&id1);

    while(!feof(file)){
        fscanf(file,"%d %s %s %d",&u.id,u.user_name,u.email,&u.number);
        if(id1 != u.id){
            printf("User removed!\n");
            fprintf(file1,"%d %s %s %d\n",u.id,u.user_name,u.email,u.number);
            found = 1;
        }
    }
    fclose(file);
    fclose(file1);
    
     remove("user.txt"); 
     rename("temp.txt","user.txt");
   }