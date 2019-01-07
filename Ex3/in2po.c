#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node1
{
  char data;
  struct node1 *back;
};
typedef struct node1 Node1;
Node1 * get_node()
{
  return (Node1 *)malloc(sizeof(Node1));
}
Node1 * push1(Node1 * top1, char a)
{
  Node1 *temp1;
  if(top1==NULL)
  {
    top1=get_node();
    top1->data=a;
    top1->back=NULL;
  }
  else
  {
    temp1=get_node();
    temp1->data=a;
    temp1->back=top1;
    top1=temp1;
  }
  return top1;
}
Node1 * pop1(Node1 *top1)
{
  Node1 *temp1=top1;
  if(top1->back==NULL)
    top1=NULL;
  else
    top1=top1->back;
  free(temp1);
  return top1;
}
char * in2po(char *infix, Node1 *top1)
{
  char *postfix=(char *)malloc(100);
  int i=0,j=0;
  while(infix[i]!='\0')
  {
    char q=infix[i];
    if(isdigit(q)!=0)
    {
      postfix[j]=q;
      j++;
    }
    else if(q=='(')
      top1=push1(top1,q);
    else if(q=='+' || q=='-')
    {
      if(top1==NULL || top1->data=='(')
	top1=push1(top1,q);
      else
      {
	postfix[j]=top1->data;
	j++;
	top1=pop1(top1);
	top1=push1(top1,q);
      }
    }
    else if(q=='*' || q=='/' || q=='%')
    {
      if(top1==NULL ||top1->data=='(' || top1->data=='+' || top1->data=='-')
	top1=push1(top1,q);
      else
      {
	postfix[j]=top1->data;
	j++;
	top1=pop1(top1);
	top1=push1(top1,q);
      }
    }
    else if(q=='^')
      top1=push1(top1,q);
    else if(q==')')
    {
      while(top1!=NULL)
      {
	if(top1->data=='(')
	{
	  break;
	}
	else
	{
	  postfix[j]=top1->data;
	  j++;
	  top1=pop1(top1);
	}
      }
    }
    i++;
  }
  while(top1!=NULL)
  {
    if(top1->data!='(')
    {
      postfix[j]=top1->data;
      j++;
    }
    top1=top1->back;
  }
  free(top1);
  return postfix;
}
void main()
{
  Node1 *top1;
  top1=NULL;
  char *postfix,*infix;
  infix=(char *)malloc(100);
  scanf("%s",infix);
  postfix=in2po(infix,top1);
  printf("Postfix: %s\n",postfix);
}
