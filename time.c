# include <stdio.h>
# include <time.h>
# include "myfunctions.h"

    void get_time(char *buffer, size_t size){
        time_t t; 
        struct tm *tm_info;

        time(&t);
        tm_info = localtime(&t);
         
        strftime(buffer, size, "%b %d %I %p", tm_info);
    }