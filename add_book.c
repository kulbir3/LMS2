# include <stdio.h>
# include <stdlib.h>
# include "myfunctions.h"

void add_book(){
  FILE *ptr = fopen("Book.txt","a");
  if(ptr == NULL){
    printf("Error!");
    return ;
  }
     printf("Enter Book id: ");
     scanf("%d",&b.id);
     
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

     fprintf(ptr," %d %s  %s  %s %d\n",b.id, b.name, b.author, b.genre, b.cpy);

     fclose(ptr);
     printf("\nBook added successfully.....\n");
}