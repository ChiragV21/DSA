// https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1/
//The Total Time Complexity is O(logn).
#include<bits/stdc++.h>
using namespace std;
int search(int arr[],int n,int x,bool findidx){
	    int start=0,end=n-1;
	    int ans=-1;
	    while(start<=end){
	        int mid=start+(end-start)/2;
	        
	        if(arr[mid]>x)
	            end=mid-1;
	        else if(arr[mid]<x)
	            start=mid+1;
	        else{
	           ans=mid;
	           if(findidx)
	             end=mid-1;
	           else
	             start=mid+1;
	       }
	    }
	    return ans;
	}
	int count(int arr[], int n, int x) {
	    // code here
	    int first=-1,second=-1;
	    first=search(arr,n,x,true);
	    if(first!=-1)
	        second=search(arr,n,x,false);
	   
	    int res=0;
	    if(first==-1 and second==-1){
	        return res;
	    }
	    
	    else{
	        res=second-first+1;
	    }
	    return res;
	}
int main(){
    int n,target;
    cin>>n>>target;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<count(arr,n,target)<<endl;
    return 0;
}