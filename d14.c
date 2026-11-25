#include<stdio.h>
# define MAX 5
int stack[MAX];
int top=-1;
void push(){
 int x;
 if(top==MAX-1)
 printf("stack overflow");
 else{
  printf("Enter the stack elements:");
  scanf("%d",&x);
  stack[++top]=x;
 }
}
void pop(){
 if(top==-1)
 printf("stack underflow");
 else{
  printf("popped elements:%d\n",stack[top--]);
 }
}
void display(){
 int i;
 if(top==-1)
 printf("stack is empty");
 else{
  printf("stack elements:");
  for(i=top;i>=0;i--)
  printf("%d",stack[i]);
  printf("\n");
 }
}
int main(){
 int ch;
 do{
  printf("\n 1.push \n 2.pop \n 3.display \n 4.exit");
  printf("Enter your choice:");
  scanf("%d",&ch);
  switch(ch){
   case 1:push();break;
   case 2:pop();break;
   case 3:display();break;
   case 4:printf("exit \n");break;
   default:printf("Invalid choice!");
   }
 }while(ch!=4);
 return 0;
}
