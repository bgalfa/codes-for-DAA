#include<stdio.h>
#include<stdlib.h>
int search(int*p,int lb,int ub,int key);
int dupli(int*p,int n,int i);
int main(){
int tn,test[10],n,*p,cmp,key,f,i;
printf("Enter number of cases:");
scanf("%d",&tn);
p=test;
p=(int*)malloc(tn*sizeof(int));
p=NULL;
while(tn){
    f=0;
    printf("\nNew Aray\nEnter number of elements");
    scanf("%d",&n);
    printf("Enter sorted array");
    p=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",(p+i));
    }
    printf("\nEnter key to find:");
    scanf("%d",&key);
    i=search(p,0,n,key);
    if(i==-1)
    printf("\nElement not present");
    else{
    f=dupli(p,n,i);
    printf(" present at index %d frequency =%d",i,f);
    }
    free(p);
    tn--;
}
}
int search(int*p,int lb,int ub,int key){
   int mid=(lb+ub)/2;
   if(lb<=ub){
   if(*(p+mid)==key){
       return mid;
   }
   else if(key<*(p+mid))
   return search(p,lb,mid-1,key);
   else
   return search(p,mid+1,ub,key);
   }
   return -1;
}
int dupli(int*p,int n,int i){
    int c=0,t=*(p+i);
    while(*(p+i-1)==t&&i>=0){
    c=c+1;
    i--;
}
while(*(p+i+1)==t&&i<=n){
    c=c+1;
    i++;
}
return c+1;
}
