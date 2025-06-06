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
    char buf[256];
    printf("Enter ID to remove user: ");
    scanf("%d",&id1);

    while(fgets(buf, sizeof(buf), file)){
        if(sscanf(buf, "Id:%d|Name:%[^|]|Email:%[^|]|Number:%d",&u.id, u.user_name, u.email, &u.number) == 4){
        if(id1 != u.id){
            found = 1;
            fprintf(file1, "Id:%d|Name:%s|Email:%s|Number:%d\n",u.id, u.user_name, u.email, u.number);
        }
    }
}
    fclose(file);
    fclose(file1);
    
     remove("user.txt"); 
     rename("temp.txt","user.txt");

     if(found){
        printf("User removed!\n");
     }else{
        printf("User with %d Id not found.\n",u.id);
     }
   }