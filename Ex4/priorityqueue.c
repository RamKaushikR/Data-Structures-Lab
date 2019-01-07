#include<stdio.h>
#include<stdlib.h>
struct node
{
  int key,priority;
  struct node *next;
};
typedef struct node Node;
Node *getnode()
{
  return (Node *)malloc(sizeof(Node));
}
void enque(Node **front, Node **rear)
{
  Node *t;
  int n,p;
  scanf("%d%d",&n,&p);
  while(n!=-1)
  {
    t=getnode();
    t->key=n;
    t->priority=p;
    t->next=NULL;
    if((*front)==NULL)
    {
      (*front)=t;
      (*rear)=t;
    }
    else
    {
      (*rear)->next=t;
      (*rear)=t;
    }
    scanf("%d%d",&n,&p);
  }
}
void deque(Node **front)
{
  Node *p;
  while((*front)!=NULL)
  {
    p=*front;
    printf("%d:%d ",p->key,p->priority);
    (*front)=(*front)->next;
    free(p);
  }
} 
void order(Node **front, Node **rear)
{
  Node *i,*j;
  int k=0,a,b;
  for(i=(*front);i->next!=NULL;i=i->next)
  {
    for(j=i->next;j!=NULL;j=j->next)
    {
      if(i->priority<j->priority)
      {
	a=i->key;
	b=i->priority;
	i->key=j->key;
	i->priority=j->priority;
	j->key=a;
	j->priority=b;
      }
    }
    if(k==0)
      (*front)=i;
    k++;
  }
  (*rear)=i;
}
int main()
{
  Node *front=NULL,*rear=NULL;
  printf("Add elements with priority\n");
  enque(&front,&rear);
  order(&front,&rear);
  deque(&front);
  printf("\n");
}
