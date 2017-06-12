#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000//note that this is not the max of an int
void merge(int* A,int p,int q,int r){
  int n1=q-p+1;
  int n2=r-q;
  int* L1=malloc(sizeof(int)*(n1+1));
  int* L2=malloc(sizeof(int)*(n2+1));
  for(int i=1;i<=n1;i++)
    L1[i-1]=A[p+i-1];
  L1[n1]=MAX;
  for(int i=1;i<=n2;i++)
    L2[i-1]=A[q+i];
  L2[n2]=MAX;
  int i=0;
  int j=0;
  for(int n=p;n<=r;n++){
    if(L1[i]<=L2[j]){
      A[n]=L1[i];
      i++;
    }else{
      A[n]=L2[j];
      j++;
    }
  }
  free(L1);
  free(L2);
}
void merge_sort(int* A,int p,int r){
  if(p<r){
    int q=(p+r)/2;
    merge_sort(A,p,q);
    merge_sort(A,q+1,r);
    merge(A,p,q,r);
  }
}
void printArray(int* A,int size){
  for(int i=0;i<size;i++)
    printf("%d ",A[i]);
  printf("\n");
}
void main(){
  int A[9]={6,2,9,3,7,11,4,15,13};
  printArray(A,9);
  merge_sort(A,0,8);
  printArray(A,9);
}
