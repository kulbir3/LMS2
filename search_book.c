# include <stdio.h>
# include <string.h>
# include "myfunctions.h"

  void search_book(){
    FILE *ptr = fopen("Book.txt","r");
    if(ptr == NULL){
        printf("Error opening file!");
        return;
    }
    char bg[50];
    int found = 0;

    printf("Book/genre to search: ");
    getchar();
    scanf("%[^\n]",bg);

    while(fscanf(ptr,"%d %s %s %s",&b.id,b.name,b.author,b.genre) == 4){
      if((strcmp(bg,b.name) == 0)||(strcmp(bg,b.genre) == 0)){
        printf("Book found!\n");
        printf("\nID: %d\nName: %s\nAuthor: %s\nGenre: %s\n",b.id,b.name,b.author,b.genre);
        found = 1;
      }
    }
    if(!found){
      printf("Book not found!\n");
    }
    fclose(ptr);
  }
  