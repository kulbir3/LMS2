# include <stdio.h>
# include "myfunctions.h"

  void search_user(){
    FILE *ptr = fopen("user.txt","r");
    if(ptr == NULL){
       printf("Error opening file!");
       return;
    }
    int id1;
    int found = 0;
    char buf[256];

    printf("Enter Id to search: ");
    scanf("%d",&id1);

    while(fgets(buf, sizeof(buf), ptr)){
      if(sscanf(buf, "Id:%d|Name:%[^|]|Email:%[^|]|Number:%d",&u.id,u.user_name,u.email,&u.number) == 4){
      if(id1 == u.id){
        printf("User found!\n");
        printf("ID: %d\nName: %s\nEmail: %s\nNumber: %d\n",u.id,u.user_name,u.email,u.number);
        found = 1;
        break;
      }
    }
  }
    if(!found){
      printf("User not found!\n");
    }
    fclose(ptr);
  }
  
 