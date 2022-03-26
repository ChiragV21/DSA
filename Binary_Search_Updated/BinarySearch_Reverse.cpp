#include<bits/stdc++.h>
using namespace std;
//Array is sorted in reverse order.
//eg. 90,76,18,12,6,4,3,1.
int SearchinArray(int arr[],int n,int key){
    int start=0,end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]>key){
            start=mid+1;
        }
        else if(key>arr[mid]){
            end=mid-1;
        }
        else
            return mid;
    }
    return -1;
}
int main(){
    int n,key;
    cin>>n>>key;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<SearchinArray(arr,n,key);
    return 0;
}