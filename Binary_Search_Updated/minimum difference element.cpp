#include<bits/stdc++.h>
using namespace std;
int MinimumDifferenceElement(int arr[],int n,int target){
    int start=0,end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]>target){
            end=mid-1;
        }
        else if(target>arr[mid]){
            start=mid+1;
        }
        else
            return arr[mid];
    }
    int x=abs(arr[end]-target);
    int y=abs(arr[start]-target);
    if(x>y)
        return arr[start];
    else
        return arr[end];
}
int main(){
    int n,target;
    cin>>n>>target;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<MinimumDifferenceElement(arr,n,target);
    return 0;
}