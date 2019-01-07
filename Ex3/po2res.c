#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
struct node{
  int key;
  struct node *back;
};
typedef struct node Node;
Node * getnode()
{
  return (Node *)malloc(sizeof(Node));
}
Node * push(Node * top, int a)
{
  Node *temp;
  if(top==NULL)
  {
    top=getnode();
    top->key=a;
    top->back=NULL;
  }
  else
  {
    temp=getnode();
    temp->key=a;
    temp->back=top;
    top=temp;
  }
  return top;
}
Node * pop(Node *top)
{
  Node *temp=top;
  top=top->back;
  free(temp);
  return top;
}
void po2res(char *postfix, Node *top)
{
  int k=0,b[2],result;
  while(postfix[k]!='\0')
  {
    if(isdigit(postfix[k]))
    {
      int a=(int)postfix[k]-(int)'0';
      top=push(top,a);
    }
    else
    {
      for(int j=0;j<2;j++)
      {
	b[j]=top->key;
	top=pop(top);
      }
      if(postfix[k]=='+')
	result=b[1]+b[0];
      else if(postfix[k]=='-')
	result=b[1]-b[0];
      else if(postfix[k]=='*')
	result=b[1]*b[0];
      else if(postfix[k]=='/')
	result=b[1]/b[0];
      else if(postfix[k]=='%')
	result=b[1]%b[0];
      else if(postfix[k]=='^')
	result=pow(b[1],b[0]);
      top=push(top,result);
      printf("%d%c%d=%d\n",b[1],postfix[k],b[0],result);
    }
    k++;
  }
}
void main()
{
  Node *top;
  top=NULL;
  char *postfix=(char *)malloc(100);
  scanf("%s",postfix);
  po2res(postfix,top);
}
