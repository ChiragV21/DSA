#include<bits/stdc++.h>
using namespace std;
bool isPowerof3(int n){
    if(n==1)
        return true;
    if(n<=0 or n%3!=0)
        return false;
    return isPowerof3(n/3);
}
int main(){
    int n;
    cin>>n;
    if(isPowerof3(n))
        cout<<"YES"<<endl;
    else    
        cout<<"NO"<<endl;
    return 0;
}