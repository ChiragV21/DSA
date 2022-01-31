//In this allow circular check in the Array.
#include<bits/stdc++.h>
using namespace std;
vector<int> nextgreater(int arr[],int n){
    vector<int> nge(n,-1);
    stack<int> st;
    for(int i=2*n-1;i>=0;i--){
        while(!st.empty() and st.top()<=arr[i%n]){
            st.pop();
        }

        if(i<n){
            if(st.empty()==false)
                nge[i]=st.top();
        }
        st.push(arr[i%n]);
    }
    return nge;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> res=nextgreater(arr,n);
    for(auto i:res)
        cout<<i<<" ";
    return 0;
}

//Time Complexity and Space is O(N) and O(N).
