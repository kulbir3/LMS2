# include <stdio.h>
# include <string.h>
# include "myfunctions.h"
char user_exists(char *user_id){

    char buf[256];
    printf("User Id : %s", user_id);
    FILE *file = fopen("user.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    while (fgets(buf, sizeof(buf), file)){
        if(sscanf(buf, "Id:%[^|]|Name:%[^|]|Email:%[^|]|Number:%lld", u.id, u.user_name, u.email,&u.number) !=EOF){
        if (strcmp(u.id, user_id)==0) {
            fclose(file);
            return 1;
        }
    }
}
    fclose(file);
    return 0;
}