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
    char buf[256];

    printf("Book/genre to search: ");
    getchar();
    scanf("%[^\n]",bg);

    while(fgets(buf, sizeof(buf), ptr)){
      if(sscanf(buf, "Id:%[^|]|Name:%[^|]|Author:%[^|]|Genre:%[^|]|Copies:%d",b.id, b.name, b.author, b.genre, &b.cpy) != 5){
        continue;
      }
      if(strstr(b.name, bg)||strstr(b.genre, bg)){
        printf("Book found!\n");
        printf("\nID: %s\nName: %s\nAuthor: %s\nGenre: %s\nCopies: %d\n",b.id, b.name, b.author, b.genre, b.cpy);
        found = 1;
      }
    }
    if(!found){
      printf("Book not found!\n");
    }
    fclose(ptr);
  }
  