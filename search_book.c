# include <stdio.h>
# include "myfunctions.h"

  void search_book(){
    FILE *ptr = fopen("Book.txt","r");
    if(ptr == NULL){
        printf("Error opening file!");
        return;
    }
    int id1;
    int found = 0;

    printf("Enter Id to search: ");
    scanf("%d",&id1);

    while(!feof(ptr)){
      fscanf(ptr,"%d %s %s %s",&b.id,b.name,b.author,b.genre);
      if(id1 == b.id){
        printf("Book found!\n");
        printf("ID: %d\nName: %s\nAuthor: %s\nGenre: %s\n",b.id,b.name,b.author,b.genre);
        found = 1;
        break;
      }
    }
    if(!found){
      printf("Book not found!\n");
    }
    fclose(ptr);
  }
  