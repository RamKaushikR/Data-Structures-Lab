#include<stdio.h>
#include<stdlib.h>
struct node
{
  int key;
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
  int n;
  scanf("%d",&n);
  while(n!=-1)
  {
    t=getnode();
    t->key=n;
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
    scanf("%d",&n);
  }
  (*rear)->next=*front;
  printf("Rear=%d\n",(*rear)->key);
}
void deque(Node **front, Node **rear)
{
  Node *p;
  while((*front)!=(*rear))
  {
    p=*front;
    printf("Front=%d\n",(*front)->key);
    (*front)=(*front)->next;
    free(p);
  }
  p=*front;
  *front=*rear=NULL;
  printf("Front=%d\n",p->key);
  free(p);
} 
int main()
{
  Node *front=NULL,*rear=NULL;
  enque(&front,&rear);
  printf("Add elements\n");
  enque(&front,&rear);
  deque(&front,&rear);
}
