// https://www.geeksforgeeks.org/search-almost-sorted-array/
#include<bits/stdc++.h>
using namespace std;
int SearchinArray(int arr[],int n,int key){
    int start=0,end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key)
            return mid;
        
        if(mid-1>=start and arr[mid-1]==key)
            return (mid-1);

        if(mid+1<=end and arr[mid+1]==key)
            return (mid+1);
            
        else if(arr[mid]>key){
            end=mid-2;
        }
        else if(key>arr[mid]){
            start=mid+2;
        }
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