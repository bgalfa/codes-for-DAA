/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>

int hash1(int num,int sz_arr){
    return num%sz_arr;
}
int hash(int arr[],int num,int size_arr,int i){
    int idx,c1=2,c2=1;
    do{
        idx=(hash1(num,size_arr)+c1*i+c2*i*i)%size_arr;
        i++;
    }while(arr[idx]!=0);
    return idx;
}
int hash_finder(int arr[],int num,int size_arr,int i){
    int idx,c1=2,c2=1,t=i;
    do{
        idx=(hash1(num,size_arr)+c1*i+c2*i*i)%size_arr;
        i++;
        if(arr[idx]==num){
            return 1;
        }
    }while(i<size_arr);

    return 0;
}
int main()
{
    int idx,n,x,m,sz2=0,j=0,f;
    printf("Enter size of both arrays:");
    scanf("%d %d",&n,&m);
    int a2=n>m?n:m,a3=n<m?n:m;
    int hasharr[a2],arr2[a3];
    for(int i=0;i<a2;i++){
        hasharr[i]=0;
    }
    printf("Enter array elemnts:");
    for(int i=0;i<a2;i++){
        scanf("%d",&x);
        int t=hash(hasharr,x,a2,i);
        hasharr[t]=x;
    }
    for(int i=0;i<a2;i++)
        printf("%d\t",hasharr[i]);
    printf("\nEnter next array elemnts;");
    for(int i=0;i<a3;i++){
        scanf("%d",&x);
        f=hash_finder(hasharr,x,a2,i);
        if(f==1){
            arr2[j]=x;
            j++;
        }
    }
    printf("Intersection points");
    for(j=j-1;j>-1;j--)
        printf("%d\t",arr2[j]);
   
    return 0;
}
