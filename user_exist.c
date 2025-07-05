# include <stdio.h>
# include "myfunctions.h"
int user_exists(int user_id){

    char buf[256];
    printf("User Id : %d", user_id);
    FILE *file = fopen("user.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    while (fgets(buf, sizeof(buf), file)){
        if(sscanf(buf, "Id:%d|Name:%[^|]|Email:%[^|]|Number:%lld", &u.id, u.user_name, u.email,&u.number) !=EOF){
        if (u.id == user_id) {
            fclose(file);
            return 1;
        }
    }
}
    fclose(file);
    return 0;
}