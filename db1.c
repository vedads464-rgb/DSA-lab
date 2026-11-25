#include <stdio.h>
#include<ctype.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push (char c)
{
 stack[++top]=c;
 }
 char pop()
 {
  return stack [top--];
 }
 int precedence (char c)
 {
  if (c=='^')return 3;
  if(c=='*'||c=='/'||c=='%') return 2;
  if(c=='+'||c=='-') return 1;
  return 0;
 }
 int isOperator(char c)
 {
 return c=='+'||c=='-'||c=='*'||c=='/'||c=='%'||c=='^';
 }
 int isMatch(char a, char b)
 {
  return (a=='('&& b==')')||(a=='{'&& b=='}')||(a=='['&& b==']');
 }
 int convert(char infix[], char postfix[])
 {
 int i,j=0,expect=1;
 char c;
 top=-1;
 for(i=0;infix[i]!='\0';i++)
 {
  c=infix[i];
  if(isspace(c))
  continue;
  if(isalnum(c))
  {
  if(!expect) return 0;
  postfix[j++]=c;
  expect=0;
  }
  else if(c=='('|| c=='{'|| c=='[')
  {
   if(!expect) return 0;
   push(c);
  }
  else if(c==')'||c=='}'||c==']')
  {
  if(expect||top==-1)
  return 0;
  int found = 0;
  for(int k=top;k>=0;k--)
  {
  if(stack[k]=='('||stack[k]=='{'||stack[k]=='[')
  {
  if(isMatch(stack[k],c))
  found = 1;
  break;
  }
  }
  if(!found)
  return 0;
  while(top!=-1 &&
  stack[top]!='(' &&
  stack[top]!='{' &&
  stack[top]!='[')
  {
  postfix[j++] = pop();
  }
  pop();
  expect = 0;
 }
 else if(isOperator(c))
 {
  if(expect) return 0;
  while(top!=-1 && precedence(stack[top])>0 && (precedence(stack[top])>precedence(c)||(precedence(stack[top])==precedence(c) && c!='^')))
  {
   postfix[j++]= pop();
  }
  push(c);
  expect = 1;
 }
 else
 return 0;
 }
 if(expect)
 return 0;
 while(top!=-1)
 {
  if(stack[top]=='('|| stack[top]=='{'|| stack[top]=='[')
  return 0;
  postfix[j++]=pop();
 }
 postfix[j]='\0';
 return 1;
 }
 int main()
 {
  char infix[MAX], postfix[MAX];
  printf("Enter infix expression:");
  fgets(infix,MAX,stdin);
  if(convert(infix,postfix))
  {
   printf("\n Valid Expression");
   printf("\n Postfix Experession: %s\n", postfix);
  }
  else
  {
   printf("\nInvalid Experession!\n");
  }
  return 0;
 }
 
