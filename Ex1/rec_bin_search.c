#include<stdio.h>
#define N 1000
void sort(int a[], int n){
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(a[j]<a[i]){
	int t=a[i];
	a[i]=a[j];
	a[j]=t;
      }
    }
  }
}
int binary_search(int a[], int b, int e, int val){
  static int c=0;
  while(b<=e)
  { c++;
    int m=(b+e)/2;
    if(a[m]==val)
    {
      printf("%d\n",c);
      return m;
    }
    else if(a[m]<val)
      return binary_search(a,m+1,e,val);
    else
      return binary_search(a,b,m-1,val);
    
  }
  printf("%d\n",c);
  return -1;
}
int main(){
  int a[N],n,q;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&q);
  int s=binary_search(a,0,n-1,q);
  printf("%d\n",s);
}
