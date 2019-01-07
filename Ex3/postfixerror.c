#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
struct node{
  int key;
  struct node *back;
};
typedef struct node Node;
struct node1
{
  char data;
  struct node1 *back;
};
typedef struct node1 Node1;
Node * getnode()
{
  return (Node *)malloc(sizeof(Node));
}
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
      int f=0;
      Node1 *temp1=top1;
      while(temp1!=NULL)
      {
	if(temp1->data=='(')
	{
	  f=1;
	  break;
	}
	temp1=temp1->back;
      }
      if(f==0)
	return "Error";
      while(top1!=NULL)
      {
	if(top1->data=='(')
	{
	  top1=pop1(top1);
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
    else
      return "Error";
    top1=pop1(top1);
  }
  return postfix;
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
  FILE *fp;
  fp=fopen("postfixerror.in","r");
  Node *top;
  Node1 *top1;
  top=NULL;
  top1=NULL;
  char *postfix,*infix;
  infix=(char *)malloc(100);
  fscanf(fp,"%s",infix);
  postfix=in2po(infix,top1);
  printf("%s\n",postfix);
  if(strcmp(postfix,"Error")!=0)
    po2res(postfix,top);
}
