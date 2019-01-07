#include<stdio.h>
#include<stdlib.h>
struct node
{
  int coeff,pow;
  struct node *next;
};
typedef struct node Node;
Node * getnode()
{
  return (Node *)malloc(sizeof(Node));
}
Node * assign(Node * a, int n)
{
  Node *q,*t;
  int b;
  q=getnode();
  for(int i=n;i>=0;i--)
  {
    scanf("%d",&b);
    if(a==NULL)
    {
      a=getnode();
      a->coeff=b;
      a->pow=i;
      a->next=NULL;
      q=a;
     
    }
    else
    {
      t=getnode();
      t->coeff=b;
      t->pow=i;
      t->next=NULL;
      q->next=t;
      q=t;
    }
  }
  return a;
}
Node * sum1(Node * a, Node * b, Node * sum)
{
  Node *q,*t;
  q=getnode();
  for(;a!=NULL && b!=NULL;a=a->next,b=b->next)
  {
    if(sum==NULL)
    {
      sum=getnode();
      sum->coeff=a->coeff+b->coeff;
      sum->pow=a->pow;
      sum->next=NULL;
      q=sum;
    }
    else
    {
      t=getnode();
      t->coeff=a->coeff+b->coeff;
      t->pow=a->pow;
      t->next=NULL;
      q->next=t;
      q=t;
    }
  }
  return sum;
}
void display(Node *a)
{
  Node *t;
  for(t=a;t!=NULL;t=t->next)
    printf("%dx^%d%c",t->coeff,t->pow,t->next==NULL?' ':'+');
  printf("\n");
}
int main()
{
  Node *eq1,*eq2,*sum;
  int n;
  eq1=NULL;
  eq2=NULL;
  sum=NULL;
  scanf("%d",&n);
  eq1=assign(eq1,n);
  eq2=assign(eq2,n);
  sum=sum1(eq1,eq2,sum);
  display(eq1);
  display(eq2);
  display(sum);
}
  
  
