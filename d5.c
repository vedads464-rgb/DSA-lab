#include<stdio.h>
#define MAX 3
int queue[MAX];
int front = 0;
int rear = -1;
int count = 0;
void add(){
 int id;
 if (count==MAX){
  printf("Queue overflow! The printer gueue is full");
  return;
 }
 printf("Enter the print job ID:");
 scanf("%d",&id);
 rear= (rear+1)%MAX;
 queue[rear]=id;
 count++;
 printf("The job %d added\n",id);
}
void process(){
 if(count==0){
  printf("Queue underflow! No print jobs are waiting \n");
  return;
 }
 printf("Processing the job %d \n",queue[front]);
 front =(front+1)%MAX;
 count--;
}
void display(){
 int index = front;
 if(count==0){
  printf("Number of print jobs waiting:%d\n",count);
  return;
  }
  else{
  printf("Jobs in queue are:\n");
  for(int i=0;i<count;i++){
   printf("Job %d \n",queue[index]);
   index=(index+1)%MAX;
  }
  }
}
void main(){
 int ch;
 do{
  printf("\n 1.add \n2.process\n3.display\n4.exit");
  printf("\n Enter choice:");
  scanf("%d",&ch);
  switch(ch){
   case 1: add(); break;
   case 2: process(); break;
   case 3: display(); break;
   case 4: printf("Exit");
   default: printf("\nInvalid choice");
   }
   }while(ch!=4);
   }
