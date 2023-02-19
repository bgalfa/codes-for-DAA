#include<iostream>
#include<math.h>
using namespace std;
int jumpsearch(int a[],int n,int key,int k){
    int idx= pow(2,k);
    if(idx<n){
        if(key>a[idx])
            return jumpsearch(a,n,key,k+1);
        else if(a[idx]==key)
            return idx;
        else{
            if(key<a[idx]){
            for(int i=idx;i>pow(2,k-1)&&i>0;i--){
                if(a[i]==key)
                return i;
            }
            }
        }
    }
    else return -1;
}
void display(int a[],int n){
    for(int i=0;i<n;i++){
        if(i%2==0)
            cout<<endl;
        cout<<a[i]<<" ";
    }
}
int main(){
    int n,key,ans;
    cout<<"Enter number of elements of array :";
    cin>>n;
    int a[n];
    cout<<"Enter array elemtns :\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter key you want to search!";
    cin>>key;
    display(a,n);
    ans=jumpsearch(a,n,key,0);
    if(ans==-1)
    cout<<"Element not found";
    else
    cout<<"Present at index "<<ans;
}