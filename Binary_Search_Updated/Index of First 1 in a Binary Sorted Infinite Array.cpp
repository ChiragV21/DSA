#include<bits/stdc++.h>
using namespace std;
int FirstOccurenceinArray(int arr[],int start,int end,int target){
    int res=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==target){
            res=mid;
            end=mid-1;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
        else if(target>arr[mid]){
            start=mid+1;
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int target=1;
    int start=0,high=1;
    while(target>arr[high]){
        start=high;
        high=high*2;
    }

    cout<<FirstOccurenceinArray(arr,start,high,target)<<endl;
    return 0;
}