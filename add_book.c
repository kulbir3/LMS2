# include <stdio.h>
# include <string.h>
# include "myfunctions.h"

void add_book(){
  FILE *ptr, *ptr1;
    int temp_cpy;
    char temp_na[30], temp_au[20],temp_ge[100];
    char choice, buf[256], temp_id[20];
   
    ptr1 = fopen("Book.txt","r");
    if(ptr1 == NULL){
      ptr1 = fopen("Book.txt","w");
    }
  
     printf("Enter Book Id: ");
     getchar();
     scanf("%[^\n]",b.id);
     if(!valid_id(b.id)){
      printf("Invalid id!\n");
      return;
     }

     while(fgets(buf, sizeof(buf), ptr1)){
      if(sscanf(buf, "Id:%[^|]|Name:%[^|]|Author:%[^|]|Genre:%[^|]|Copies:%d",temp_id, temp_na, temp_au, temp_ge, &temp_cpy) == 5){
        if(strcmp(b.id,temp_id)==0){
          printf("Book id already exist!\n");
          fclose(ptr1);
          return;
       } 
     }
  }
     
     ptr = fopen("Book.txt","a");
     if(ptr == NULL){
      printf("Error opening file!\n");
      return;
     }
     
     printf("Enter Book name: ");
     getchar();
     scanf("%[^\n]",b.name);
     if(!valid_name(b.name)){
      printf("Inavlid name!\n");
      return;
     }

     printf("Enter Author name: ");
     getchar();
     scanf("%[^\n]",b.author);
     if(!valid_name(b.author)){
      printf("Invalid name!\n");
      return;
     }

     printf("Enter Book genre: ");
     getchar();
     scanf("%[^\n]",b.genre);
     if(!valid_genre(b.genre)){
      printf("Invalid genre!\n");
      return;
     }

     printf("Enter book copies: ");
     scanf("%d",&b.cpy);

     fprintf(ptr, "Id:%s|Name:%s|Author:%s|Genre:%s|Copies:%d\n",b.id, b.name, b.author, b.genre, b.cpy);

     fclose(ptr);
     printf("\nBook named %s added successfully.....\n",b.name);

     }
    