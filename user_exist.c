# include <stdio.h>
# include "myfunctions.h"
int user_exists(int user_id){

    printf("User Id : %d", user_id);
    FILE *file = fopen("user.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    while (fscanf(file, "%d %s %s %d\n", &u.id, u.user_name, u.email,&u.number) != EOF) {
        if (u.id == user_id) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}