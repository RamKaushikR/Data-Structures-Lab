#include<stdio.h>
#include<stdlib.h>
struct node
{
  int key;
  struct node *next;
};
typedef struct node Node;
Node * getnode(Node * n, int val)
{
  n=(Node *)malloc(sizeof(Node));
  n->key=val;
  n->next=NULL;
  return n;
}
Node * insert(Node * head, int ref, int val)
{
  if(ref<0)
  {
    Node *t;
    t=getnode(t,val);
    t->next=head;
    head=t;
  }
  else
  {
    Node *t,*p;
    for(t=head;t->key!=ref && t->next!=NULL;t=t->next);
    p=getnode(p,val);
    p->next=t->next;
    t->next=p;
  }
  return head;
}
Node * delete(Node * head, int ref)
{
  Node *p,*t;
  if(head->key==ref)
  {
    p=head;
    head=head->next;
    free(p);
  }
  else
  {
    for(t=head;t->next->key!=ref && t->next->next!=NULL;t=t->next);
    p=t->next;
    t->next=p->next;
    free(p);
  }
  return head;
}
void display(Node * head)
{
  Node * t;
  for(t=head;t!=NULL;t=t->next)
  {
    printf("%d ",t->key);
  }
  printf("\n");
}
void main()
{
  Node *head,*temp,*prev;
  int n,ri,val,rd;
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
  display(head);
  scanf("%d %d",&ri,&val);
  head=insert(head,ri,val);
  display(head);
  scanf("%d",&rd);
  head=delete(head,rd);
  display(head);
}
