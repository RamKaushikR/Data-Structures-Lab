#include<stdio.h>
void insert(int a[], int k, int i, int q)
{
  
  if(a[k]==0)
    a[k]=q;
  else
  {
    if(q<a[k])
    {
      for(int j=i;j>=k;j--)
	a[j+1]=a[j];
      a[k]=q;
    }
    else if(q<a[k+1])
    {
      for(int j=i;j>=k+1;j--)
	a[j+1]=a[j];
      a[k+1]=q;
    }
    else
      insert(a,2*k+1,i,q);
  }
}
void print(int a[], int n)
{
  for(int i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
}
void delete(int a[], int k, int q)
{
  if(a[k]==q)
  {
    int i;
    for(i=k;a[i]!=0;i++)
      a[i]=a[i+1];
    a[i-1]=0;
  }
  else if(a[k+1]==q)
  {
    int i;
    for(i=k+1;a[i]!=0;i++)
      a[i]=a[i+1];
    a[i-1]=0;
  }
  else
    delete(a,2*k+1,q);
}
int main()
{
  int a[100],q;
  scanf("%d",&q);
  int i=0;
  while(q!=-1)
  {
    a[i]=0;
    insert(a,0,i,q);
    scanf("%d",&q);
    i++;
  }
  print(a,i);
  printf("Enter elements to be deleted\n");
  scanf("%d",&q);
  while(q!=-1)
  {
    i--;
    delete(a,0,q);
    scanf("%d",&q);
  }
  print(a,i);
}
