#include<bits/stdc++.h>
using namespace std;
int search(vector<int>&nums,int n,int target,bool idx){
        int ans=-1;
        int start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]<target)
                start=mid+1;
            else if(nums[mid]>target)
                end=mid-1;
            else{
                ans=mid;
                if(idx)
                    end=mid-1;
                else
                    start=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first=-1,second=-1;
        first=search(nums,nums.size(),target,true);
        if(first!=-1)
            second=search(nums,nums.size(),target,false);
        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
int main(){
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> res=searchRange(arr,target);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    return 0;
}