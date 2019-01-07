#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
typedef struct node Node;
Node * getnode(Node * new, int val)
{
  new=(Node *)malloc(sizeof(Node));
  new->data=val;
  new->next=NULL;
  return new;
}
Node * insert(Node * head, int ref, int val)
{
  Node *t,*p;
  for(t=head;t->data!=ref && t->next!=head;t=t->next);
  p=getnode(p,val);
  p->next=t->next;
  t->next=p;
  return head;
}
Node * delete(Node * head, int ref)
{
  Node *p,*t;
  for(t=head;t->next->data!=ref && t->next!=head;t=t->next);
  p=t->next;
  t->next=p->next;
  if(head->data==ref)
    head=t->next;
  free(p);
  return head;
}
void display(Node * head)
{
  Node *t;
  t=head;
  do
  {
    printf("%d ",t->data);
    t=t->next;
  }while(t!=head);
  printf("\n");
}
void main()
{
  Node *head,*temp,*prev;
  int n,val,ri,rd;
  head=NULL;
  scanf("%d",&n);
  while(n!=-1)
  {
    if(head==NULL)
    {
      head=getnode(head,n);
      prev=head;
    }
    else
    {
      temp=getnode(temp,n);
      prev->next=temp;
      prev=temp;
    }
    scanf("%d",&n);
  }
  prev->next=head;
  display(head);
  scanf("%d %d",&ri,&val);
  head=insert(head,ri,val);
  display(head);
  scanf("%d",&rd);
  head=delete(head,rd);
  display(head);
}
