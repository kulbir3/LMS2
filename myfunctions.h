# ifndef MYFUNCTIONS_H
# define MYFUNCTIONS_H

typedef struct book{
   char name[30],author[20],genre[100], id[20]; 
   int cpy;
}book;

 typedef struct user{
   char user_name[30],email[50], id[20];
   long long number;
 }user;
 
   book b;
   user u;

      void add_book();
      void add_user();
      void display_info();
      void issue_book();
      void return_book();
      void search_book();
      void remove_user();
      void search_user();
      void Exit();
      char user_exists(char *user_id);
      void get_time(char *buffer, size_t size);
      int regex(const char *pattern, const char *text);
      int valid_num(const char *numb);
      int valid_email(const char *em);
      int valid_name(const char *na);
      int valid_id(const char *Id);
      int valid_genre(const char *ge);
      #endif