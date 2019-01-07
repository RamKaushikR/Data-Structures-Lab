#include<stdio.h>
#include<stdlib.h>
#define N 1000
struct node
{
  int key;
  struct node* next;
};
typedef struct node Node;
Node* getnode()
{
  return (Node*)malloc(sizeof(Node));
}
void display(Node* list)
{
  Node *temp;
  for(temp=list;temp!=NULL;temp=temp->next)
    printf("%d ",temp->key);
  printf("\n");
}
int search(Node* list, int val)
{
  Node *temp;
  int f=0;
  for(temp=list;temp!=NULL;temp=temp->next)
  {
    if(temp->key==val)
    {
      f=1;
      break;
    }
  }
  return f;
}
int main()
{
  Node *head, *temp, *prev;
  int n,val;
  head=NULL;
  scanf("%d",&n);
  while(n!=-1)
  {
    if(head==NULL)
    {
      head=getnode();
      head->key=n;
      head->next=NULL;
      prev=head;
    }
    else
    {
      temp=getnode();
      temp->key=n;
      temp->next=NULL;
      prev->next=temp;
      prev=temp;
    }
    scanf("%d",&n);
  }
  scanf("%d",&val);
  display(head);
  int q=search(head,val);
  printf("%d\n",q);
}
