# include <stdio.h>
# include <regex.h>
# include "myfunctions.h"

    int regex(const char *pattern, const char *text){
        regex_t regex;
        int reti = regcomp(&regex, pattern, REG_EXTENDED | REG_NOSUB);
        if(reti != 0){
            printf("Could not compile regex!\n");
            return 1;
        }
        reti = regexec(&regex, text, 0, NULL, 0);
        regfree(&regex);
        return(reti == 0);
    }
      int valid_num(const char *numb){
        return regex("^9[0-9]{9}$", numb);
      }

      int valid_email(const char *em){
        return regex("^[A-Za-z0-9]+@[A-Za-z]+\\.[A-Za-z]{2,}$", em);
      }

      int valid_name(const char *na){
        return regex("^[A-Za-z][A-Za-z ]{1,}$", na);
      }

      int valid_id(const char *Id){
         return regex("^[0-9]+$", Id);
      }

      int valid_genre(const char *ge){
         return regex("^[A-Za-z][A-Za-z -]{2,}$", ge);
      }  

      