# ifndef MYFUNCTIONS_H
# define MYFUNCTIONS_H

typedef struct book{
   char name[30],author[20],genre[100];
   int id;
}book;

 typedef struct user{
   char user_name[30],email[50];
   int id, number;
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
      int user_exists(int user_id);
      void get_time(char *buffer, size_t size);

      #endif