#include<bits/stdc++.h>
using namespace std;
int solve(int idx,int s,vector<int>& arr,int sum){
    if(idx>=arr.size()){
        if(s==sum)
            return 1;
        else
            return 0;
    }

    s+=arr[idx];
    int l=solve(idx+1,s,arr,sum);
    s-=arr[idx];
    int r=solve(idx+1,s,arr,sum);
    return l+r;
}

int printsubsequence(vector<int>& arr,int sum){
    int idx=0;
    int ans;
    int s=0;
    ans=solve(idx,s,arr,sum);
    return ans;
}
int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=printsubsequence(arr,sum);
    cout<<ans<<endl;
    return 0;
}