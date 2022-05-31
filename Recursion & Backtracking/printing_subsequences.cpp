#include<bits/stdc++.h>
using namespace std;
void solve(int idx,vector<int>&ds,vector<int>& arr,vector<vector<int>>& ans){
    if(idx>=arr.size()){
        ans.push_back(ds);
        return;
    }

    ds.push_back(arr[idx]);
    solve(idx+1,ds,arr,ans);
    ds.pop_back();
    solve(idx+1,ds,arr,ans);
}

vector<vector<int>> printsubsequence(vector<int>& arr,int n){
    vector<vector<int>> ans;
    vector<int> ds;
    int idx=0;
    solve(idx,ds,arr,ans);
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> ans=printsubsequence(arr,n);
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<",";
        }
        cout<<"]";
        cout<<endl;
    }
    return 0;
}