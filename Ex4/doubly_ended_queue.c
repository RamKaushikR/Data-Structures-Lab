#include<stdio.h>
#include<stdlib.h>
struct node
{
  int key;
  struct node *next,*back;
};
typedef struct node Node;
Node *getnode()
{
  return (Node *)malloc(sizeof(Node));
}
void enqueue(Node **front, Node **rear)
{
  Node *t;
  int n,c;
  scanf("%d%d",&n,&c);
  while(n!=-1)
  {
    t=getnode();
    t->key=n;
    t->next=t->back=NULL;
    if((*front)==NULL)
    {
      (*front)=t;
      (*rear)=t;
    }
    else if(c==1)
    {
      t->next=(*front);
      (*front)=t;
    }
    else if(c==2)
    {
      t->back=(*rear);
      (*rear)=t;
    }
    scanf("%d%d",&n,&c);
  }
  printf("Front: %d Rear: %d",(*front)->key,(*rear)->key);
}
void dequeue(Node **front, Node **rear)
{
  int c;
  Node *p;
  scanf("%d",&c);
  while((*front)!=NULL && (*rear)!=NULL)
  {
    if(c==1)
    {
      p=(*front);
      if((*front)->next==(*rear))
	(*front)=(*rear);
      else if((*front)->next!=NULL)
	(*front)=(*front)->next;
      else
      {
	(*front)=NULL;
	break;
      }
      free(p);
    }
    else if(c==2)
    {
      p=(*rear);
      if((*rear)->back==(*front))
	(*rear)=(*front);
      else if((*rear)->back!=NULL)
	(*rear)=(*rear)->back;
      else
      {
	(*rear)=NULL;
	break;
      }
      free(p);
    }
    if((*rear)==NULL)
      (*front)=(*rear);
    if((*front)==NULL)
      (*rear)=(*front);
    if((*front)!=NULL && (*rear)!=NULL)
      printf("Front: %d Rear: %d\n",(*front)->key,(*rear)->key);
    scanf("%d",&c);
  }
}
void main()
{
  Node *front=NULL, *rear=NULL;
  enqueue(&front,&rear);
  printf("\nAdd elements\n");
  enqueue(&front,&rear);
  dequeue(&front,&rear);
}
