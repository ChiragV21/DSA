#include<bits/stdc++.h>
using namespace std;
int SearchinArray(int arr[],int start,int end,int target){
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]>target){
            end=mid-1;
        }
        else if(target>arr[mid]){
            start=mid+1;
        }
        else
            return mid;
    }
    return -1;
}
int main(){
    int n,target;
    cin>>n>>target;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int start=0,high=1;
    while(target>arr[high]){
        start=high;
        high=high*2;
    }
    cout<<SearchinArray(arr,start,high,target)<<endl;
    return 0;
}