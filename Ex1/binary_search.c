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
int binary_search(int a[], int n, int val){
  int b=0,e=n-1,m;
  sort(a,n);
  while(b<=e){
    m=(b+e)/2;
    if(a[m]==val)
      return m;
    else if(a[m]<val)
      b=m+1;
    else
      e=m-1;
  }
  return -1;
}
int main(){
  int a[N],n,q;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&q);
  int s=binary_search(a,n,q);
  printf("%d\n",s);
}
