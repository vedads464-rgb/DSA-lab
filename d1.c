#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book
{
 int id;
 char title[30],author[30],status[10];
 float price;
 };
 struct Book *b;
 int n;
 
 void create()
 {
  printf("Enter number of books:");
  scanf("%d",&n);
  b=malloc(n*sizeof(struct Book));
  for(int i=0;i<n;i++){
  printf("\n Book id:");
  scanf("%d",&b[i].id);
  printf("Title:");
  scanf("%s",b[i].title);
  printf("Author:");
  scanf("%s",b[i].author);
  printf("Price:");
  scanf("%f",&b[i].price);
  strcpy(b[i].status,"Available");
  }
 }
  void display()
  {
   for(int i=0;i<n;i++)
   printf("\n id:%d\n title:%s\n author:%s\n price:%f\n status:%s",b[i].id,b[i].title,b[i].author,b[i].price,b[i].status);
   }
   
    void search()
    {
     int id;
     printf("Enter Book id:");
     scanf("%d",&id);
     for(int i=0;i<n;i++)
     if(b[i].id==id){
      printf("\n id:%d\n title:%s\n author:%s\n price:%f\n status:%s",b[i].id,b[i].title,b[i].author,b[i].status);
      return;
      }
      printf("Book is not found!\n");
      }
      
      void issueBook()
      {
       int id;
       printf("Enter Book id:");
       scanf("%d",&id);
       for(int i=0;i<n;i++)
       if(b[i].id==id){
       if(strcmp(b[i].status,"Available")==0){
       strcpy(b[i].status,"Issued");
       printf("Book issued successfully!\n");
       }
       else("Book already issued!\n");
       return;
      }
       printf("Book is not found!\n");
       }
       
       void returnBook()
       {
        int id;
        printf("Enter Book id:");
        scanf("%d",&id);
        for(int i=0;i<n;i++)
        if(b[i].id==id){
        strcpy(b[i].status,("Available"));
        printf("Book return successfully!\n");
        return;
       }
        printf("Book is not found!\n");
        }
        
        int main()
        {
         int ch;
         do{
           printf("\n 1.Add,2.display,3.search,4.issue,5.return,6.exit");
           printf("Enter your choice:");
           scanf("%d",&ch);
           switch(ch){
            case 1:create(); break;
            case 2:display(); break;
            case 3:search(); break;
            case 4:issueBook(); break;
            case 5:returnBook(); break;
            case 6:free(b); break;
            default:printf("Invalid choice!");
            }
           }while(ch!=6);
           return 0;
          }
