#include<bits/stdc++.h>
using namespace std;
bool isPowerof2(int n){
    if(n==1)
        return true;
    if(n<=0 or n%2!=0)
        return false;
    return isPowerof2(n/2);
}
int main(){
    int n;
    cin>>n;
    if(isPowerof2(n))
        cout<<"YES"<<endl;
    else    
        cout<<"NO"<<endl;
    return 0;
}