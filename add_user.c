# include <stdio.h>
# include <string.h>
# include "myfunctions.h"

  void add_user(){
    FILE *file, *ptr, *ptr1, *ptr2;
    int temp_id,temp_num;
    char temp_na[30], temp_em[50], buf[256];

   ptr = fopen("user.txt","r");
   if(ptr == NULL){
    ptr = fopen("user.txt","w");
    }
     printf("Enter User id: ");
     scanf("%d",&u.id);

    while(fgets(buf, sizeof(buf), ptr)){
      if(sscanf(buf, "Id:%d|Name:%[^|]|Email:%[^|]|Number:%d",&temp_id, temp_na, temp_em, &temp_num) == 4){
        if(u.id == temp_id){
        printf("User id already exist!\n");
        fclose(ptr);
        return;
      }
    }
  }

    file = fopen("user.txt","a");
    if(file == NULL){
        printf("Error!");
        return;
    }
    printf("Enter User name: ");
    getchar();
    scanf("%[^\n]",u.user_name);

    ptr1 = fopen("user.txt","r");
    printf("Enter User email: ");
    getchar();
    scanf("%[^\n]",u.email);
    
     while(fgets(buf, sizeof(buf), ptr1)){
      if(sscanf(buf, "Id:%d|Name:%[^|]|Email:%[^|]|Number:%d",&temp_id, temp_na, temp_em, &temp_num) == 4){
        if(strcmp(u.email, temp_em) == 0){
        printf("User email already exist!\n");
        fclose(ptr1);
        return;
      }
    }
  }
  
    ptr2 = fopen("user.txt","r");
    printf("Enter User number: ");
    scanf("%d",&u.number);

    while(fgets(buf, sizeof(buf), ptr2)){
      if(sscanf(buf, "Id:%d|Name:%[^|]|Email:%[^|]|Number:%d",&temp_id, temp_na, temp_em, &temp_num) == 4){
        if(u.number == temp_num){
        printf("User number already exist!\n");
        fclose(ptr2);
        return;
      }
    }
  }

    fprintf(file, "Id:%d|Name:%s|Email:%s|Number:%d\n",u.id, u.user_name, u.email, u.number);

    fclose(file);
    printf("User added successfully.....\n");
  }
