# include <stdio.h>
# include <string.h>
# include "myfunctions.h"

   void remove_user(){
    FILE *file = fopen("user.txt","r");
    FILE *file1 = fopen("temp.txt","w");
    if(file == NULL || file1 == NULL){
        printf("Error opening file!");
        return;
    }
    char id1[20];
    int found = 0;
    char buf[256];
    printf("Enter ID to remove user: ");
    getchar();
    scanf("%[^\n]",id1);

    while(fgets(buf, sizeof(buf), file)){
        if(sscanf(buf, "Id:%[^|]|Name:%[^|]|Email:%[^|]|Number:%lld",u.id, u.user_name, u.email, &u.number) == 4){
        if(strcmp(id1,u.id) !=0){
            fprintf(file1, "Id:%s|Name:%s|Email:%s|Number:%lld\n",u.id, u.user_name, u.email, u.number);
        }else{
            found = 1;
        }
    }
}
    fclose(file);
    fclose(file1);

     if(found){
       printf("User named %s removed!\n",u.user_name);
       remove("user.txt"); 
       rename("temp.txt","user.txt");
     }else{
        printf("User with %s Id not found.\n",u.id);
        remove("temp.txt");
     }
   }