# include <stdio.h>
# include <string.h>
# include "myfunctions.h"

  void search_user(){
    FILE *ptr = fopen("user.txt","r");
    if(ptr == NULL){
       printf("Error opening file!");
       return;
    }
    char id1[20];
    int found = 0;
    char buf[256];

    printf("Enter Id to search: ");
    getchar();
    scanf("%[^\n]",id1);

    while(fgets(buf, sizeof(buf), ptr)){
      if(sscanf(buf, "Id:%[^|]|Name:%[^|]|Email:%[^|]|Number:%lld",u.id,u.user_name,u.email,&u.number) == 4){
      if(strcmp(id1,u.id)==0){
        printf("User found!\n");
        printf("ID: %s\nName: %s\nEmail: %s\nNumber: %lld\nBook:%s\n",u.id,u.user_name,u.email,u.number, b.name);
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
  
 