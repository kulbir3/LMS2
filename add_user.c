# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "myfunctions.h"

  void add_user(){
    FILE *file, *ptr, *ptr1, *ptr2;
    int temp_id;
    long long temp_num;
    char temp_na[30], temp_em[50], buf[256],number[100];

   ptr = fopen("user.txt","r");
   if(ptr == NULL){
    ptr = fopen("user.txt","w");
    }
     printf("Enter User id: ");
     getchar();
     scanf("%[^\n]",u.id);
     if(!valid_id(u.id)){
      printf("Invalid id!");
      return;
     }

    while(fgets(buf, sizeof(buf), ptr)){
      if(sscanf(buf, "Id:%d|Name:%[^|]|Email:%[^|]|Number:%lld",&temp_id, temp_na, temp_em, &temp_num) == 4){
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
    if(!valid_name(u.user_name)){
      printf("Invalid name!\n");
      return;
    }

    ptr1 = fopen("user.txt","r");
    printf("Enter User email: ");
    getchar();
    scanf("%[^\n]",u.email);

    if(!valid_email(u.email)){
      printf("Invalid email!\n");
      fclose(ptr1);
      return;
    }
    
     while(fgets(buf, sizeof(buf), ptr1)){
      if(sscanf(buf, "Id:%d|Name:%[^|]|Email:%[^|]|Number:%lld",&temp_id, temp_na, temp_em, &temp_num) == 4){
        if(strcmp(u.email, temp_em) == 0){
        printf("User email already exist!\n");
        fclose(ptr1);
        return;
      }
    }
  }
  
    ptr2 = fopen("user.txt","r");
    printf("Enter User number: ");
    scanf("%s",number);

    if(!valid_num(number)){
      printf("Invalid number!\n");
      fclose(ptr2);
      return;
    }
   u.number = atoll(number);
    while(fgets(buf, sizeof(buf), ptr2)){
      if(sscanf(buf, "Id:%d|Name:%[^|]|Email:%[^|]|Number:%lld",&temp_id, temp_na, temp_em, &temp_num) == 4){
        if(u.number == temp_num){
        printf("User number already exist!\n");
        fclose(ptr2);
        return;
      }
    }
  }

    fprintf(file, "Id:%d|Name:%s|Email:%s|Number:%lld\n",u.id, u.user_name, u.email, u.number);

    fclose(file);
    printf("User %s added successfully.....\n",u.user_name);
  }
