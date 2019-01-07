#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next,*back;
};
typedef struct node Node;
Node * getnode()
{
  return (Node *)malloc(sizeof(Node));
}
void display(Node * head, Node * tail)
{
  Node *t=head;
  do
  {
    printf("%d ",t->data);
    t=t->next;
  }while(t!=head);
  printf("\n");
  t=tail;
  do
  {
    printf("%d ",t->data);
    t=t->back;
  }while(t!=tail);
  printf("\n");
}
Node * ins_head(Node * head, int val)
{
  Node *p;
  p=getnode();
  p->back=NULL;
  p->data=val;
  p->next=head;
  head->back=p;
  head=p;
  return head;
}
Node * ins_tail(Node * tail, int val)
{
  Node *p;
  p=getnode();
  p->data=val;
  p->back=tail;
  p->next=NULL;
  tail->next=p;
  tail=p;
  return tail;
}
Node * insert(Node * head, int ref, int val)
{
  Node *t,*p;
  for(t=head;t->data!=ref && t->next!=head;t=t->next);
  p=getnode();
  p->data=val;
  p->next=t->next;
  p->back=t;
  t->next->back=p;
  t->next=p;
  return head;
}
Node * del_head(Node * head)
{
  Node *p;
  p=head;
  head=head->next;
  free(p);
  head->back=NULL;
  return head;
}
Node * del_tail(Node * tail)
{
  Node *p;
  p=tail;
  tail=tail->back;
  free(p);
  tail->next=NULL;
  return tail;
}
Node * delete(Node * head, int ref)
{
  Node *t,*p;
  for(t=head;t->data!=ref && t->next!=head;t=t->next);
  p=t;
  t->next->back=t->back;
  t->back->next=t->next;
  free(p);
  return head;
}
void main()
{
  Node *head,*tail,*prev,*temp;
  int n,ri,val,rd;
  head=NULL;
  scanf("%d",&n);
  while(n!=-1)
  {
    if(head==NULL)
    {
      head=getnode();
      head->back=NULL;
      head->data=n;
      head->next=NULL;
      prev=head;
    }
    else
    {
      temp=getnode();
      temp->data=n;
      temp->next=NULL;
      prev->next=temp;
      temp->back=prev;
      prev=temp;
    }
    scanf("%d",&n);
  }
  tail=prev;
  tail->next=head;
  head->back=tail;
  display(head,tail);
  scanf("%d %d",&ri,&val);
  if(head->data==ri)
  {
    head=ins_head(head,val);
    head->back=tail;
    tail->next=head;
  }
  else if(tail->data==ri)
  {
    tail=ins_tail(tail,val);
    tail->next=head;
    head->back=tail;
  }
  else
    head=insert(head,ri,val);
  display(head,tail);
  scanf("%d",&rd);
  if(head->data==rd)
  {
    head=del_head(head);
    head->back=tail;
    tail->next=head;
  }
  else if(tail->data==rd)
  {
    tail=del_tail(tail);
    tail->next=head;
    head->back=tail;
  }
  else
    head=delete(head,rd);
  display(head,tail);
}
