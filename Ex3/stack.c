#include<stdio.h>
int push(int a[], int size, int top)
{
  int n;
  while(1)
  {
    if(top==size-1)
    {
      printf("Stack is full\n");
      break;
    }
    else
    {
      printf("Enter element ");
      scanf("%d",&n);
      top++;
      a[top]=n;
      printf("Do you want to continue? 1.yes 2.no ");
      int c;
      scanf("%d",&c);
      if(c==2)
	break;
    }
  }
  return top;
}
int pop(int a[], int top)
{
  while(1)
  {
    if(top==-1)
    {
      printf("Stack is empty\n");
      break;
    }
    else
    {
      printf("Top=%d\n",a[top]);
      top--;
      printf("Do you want to continue? 1.yes 2.no ");
      int c;
      scanf("%d",&c);
      if(c==2)
	break;
    }
  }
  return top;
}
void main()
{
  int size,top=-1;
  printf("Enter the size ");
  scanf("%d",&size);
  int stack[size];
  top=push(stack,size,top);
  top=pop(stack,top);
  if(top!=-1)
    printf("Top=%d\n",stack[top]);
}
