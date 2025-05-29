# include <stdio.h>
# include "myfunctions.h"

  void add_user(){
    FILE *file = fopen("user.txt","a");
    if(file == NULL){
        printf("Error!");
        return;
    }
    printf("Enter User id: ");
    scanf("%d",&u.id);

    printf("Enter User name: ");
    getchar();
    scanf("%[^\n]",u.user_name);

    printf("Enter User email: ");
    getchar();
    scanf("%[^\n]",u.email);

    printf("Enter User number: ");
    scanf("%d",&u.number);

    fprintf(file, "%d %s %s %d\n",u.id, u.user_name, u.email, u.number);

    fclose(file);
    printf("User added successfully.....\n");
  }
