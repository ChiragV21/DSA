#include<bits/stdc++.h>
using namespace std;
void solve(int idx,int s,int sum,vector<int>& ds,vector<int>& arr,vector<vector<int>>& ans){
    if(idx>=arr.size()){
        if(sum==s){
            ans.push_back(ds);
        }
        return;
    }

    ds.push_back(arr[idx]);
    s+=arr[idx];
    solve(idx+1,s,sum,ds,arr,ans);
    s-=arr[idx];
    ds.pop_back();
    solve(idx+1,s,sum,ds,arr,ans);
}
vector<vector<int>> printsubsequences(vector<int>& arr,int sum){
    vector<vector<int>> ans;
    vector<int> ds;
    int idx=0;
    int s=0;
    solve(idx,s,sum,ds,arr,ans);
    return ans;
}
int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> ans=printsubsequences(arr,sum);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}