# include <stdio.h>
# include "myfunctions.h"
 
typedef enum {
   Add_book = 1,
   Add_user,
   Display_info,
   Issue_book,
   Return_book,
   Search_book,
   Remove_user,
   Search_user,
   exit
}MenueChoice;
   book b;
   user u;

      int main(){
         int choice;

         while(1){
            printf("\n Library Management System\n");
            printf(" 1.Add book\n 2.Add user\n 3.Display_info\n 4.Issue book\n 5.Return book\n");
            printf(" 6.Search book\n 7.Remove user \n 8.Search user\n");
            printf(" 9.Exit\n");
            printf("Enter your choice: ");
            scanf("%d",&choice);
            printf("\n");
             
            MenueChoice  menueChoice = (MenueChoice)choice;

            switch(menueChoice){
               case Add_book: add_book(); break;

               case Add_user: add_user(); break;

               case Display_info: display_info(); break;

               case Issue_book: issue_book(); break;
              
               case Return_book: return_book(); break;
         
               case Search_book: search_book(); break;
              
               case Remove_user: remove_user(); break;
              
               case Search_user: search_user(); break;
              
               case exit: Exit(); break;
             
               default: printf("Invalid choice!\n");
            }
            int c;
            while((c = getchar())!='\n' && c != EOF);
            printf("\nPress any key to continue.....");
            getchar();
         }
          
         return 0;
      }

       