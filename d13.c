#include<stdio.h>
struct sparse{
 int row,col,value;
};
int main(){
 struct sparse A[10],B[10],T[10];
 int n,i;
 printf("Enter the number of non-zero elemnts:");
 scanf("%d",&n);
 printf("Enter A matrix (row col value):\n");
 for(i=0;i<n;i++)
 scanf("%d %d %d",&A[i].row,&A[i].col,&A[i].value);
 printf("Enter B matrix(row col value):\n");
 for(i=0;i<n;i++)
 scanf("%d %d %d",&B[i].row,&B[i].col,&B[i].value);
 printf("\n Addition:\n row col value \n");
 for(i=0;i<n;i++)
 printf("%d %d %d",A[i].row,A[i].col,A[i].value+B[i].value);
 printf("\nTranspose of matrix A:\n row col value\n");
 for(i=0;i<n;i++){
  T[i].row=A[i].col;
  T[i].col=A[i].row;
  T[i].value=A[i].value;
  printf("%d %d %d \n",T[i].row,T[i].col,T[i].value);
  return 0;
}
}
