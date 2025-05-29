# include <stdio.h>
# include "myfunctions.h"

void add_book(){
    int temp_id, temp_cpy;
    char temp_na[300], temp_au[20],temp_ge[100],choice;
   
    FILE *ptr1 = fopen("Book.txt","r");
    if(ptr1 == NULL){
      ptr1 = fopen("Book.txt","w");
    }

     printf("Enter Book Id: ");
     scanf("%d",&b.id);

     while(fscanf(ptr1, "%d %s %s %s %d",&temp_id, temp_na, temp_au, temp_ge, &temp_cpy) == 5){
     if(b.id == temp_id){
        printf("Book id already exist!\n");
        fclose(ptr1);
        return;
       }
     }
     
     FILE *ptr = fopen("Book.txt","a");
     if(ptr == NULL){
      printf("Error opening file!\n");
      return;
     }
     
     printf("Enter Book name: ");
     getchar();
     scanf("%[^\n]",b.name);

     printf("Enter Author name: ");
     getchar();
     scanf("%[^\n]",b.author);

     printf("Enter Book genre: ");
     getchar();
     scanf("%[^\n]",b.genre);

     printf("Enter book copies: ");
     scanf("%d",&b.cpy);

     fprintf(ptr, "Id:%d|Name:%s|Author:%s|Genre:%s|Copies:%d\n",b.id, b.name, b.author, b.genre, b.cpy);

     fclose(ptr);
     printf("\nBook added successfully.....\n");

     }