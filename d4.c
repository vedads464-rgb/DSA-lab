#include<stdio.h>
#define MAX 4
int stack[MAX],top=-1;
void push()
{
 int x;
 if(top==MAX-1)
  printf("stack overflow\n");
 
 else{
  printf("Enter element:");
  scanf("%d",&x);
  stack[++top]=x;
 }
}
 void pop(){
 if(top==-1)
  printf("Stack underflow\n");
  else
  printf("Popped element:%d\n",stack[top--]);
 }
 
 void display(){
  int i;
  if(top==-1)
   printf("Stack is empty:");
   else{
   printf("Stack element:");
   for(i=top;i>=0;i--)
   printf("%d",stack[i]);
   printf("\n");
  }
 }
 int main(){
  int ch;
  do{
   printf("\n1.push \n2.pop \n3.display \n4.exit");
   printf("\nEnter choice:");
   scanf("%d",&ch);
   switch(ch){
    case 1:push();break;
    case 2:pop();break;
    case 3:display();break;
    case 4:printf("exit\n");break;
    default:printf("Invalid choice!");
   }
  }while(ch!=4);
  return 0;
 }
