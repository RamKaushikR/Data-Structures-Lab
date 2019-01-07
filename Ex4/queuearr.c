#include<stdio.h>
int enque(int a[], int f, int *r, int s)
{
  if((*r)!=s-1)
  {  
    int b;
    scanf("%d",&b);
    (*r)++;
    a[(*r)]=b;
    if(f==-1)
      f++;
  }
  printf("Rear: %d\n",a[*r]);
  return f;
}
int deque(int a[], int f, int *r)
{
  if(f!=-1)
  {
    if((*r)==f)
    {
      f=-1;
      *r=-1;
    }
    else
    {
      f++;
      printf("Front: %d\n",a[f]);
    }
  }
  return f;
}
void main()
{
  int f=-1,r=-1,a[3],c;
  printf("1.Add 2.Delete 3.Exit\n");
  scanf("%d",&c);
  while(1)
  {
    if(c==1)
    {
      f=enque(a,f,&r,3);
      if(r==2)
	printf("Queue is full\n");
    }
    else if(c==2)
    {
      f=deque(a,f,&r);
      if(f==-1)
	printf("Queue is empty\n");
    }
    else if(c==3)
      break;
    printf("1.Add 2.Delete 3.Exit\n");
    scanf("%d",&c);
  }
}
