#include <bits/stdc++.h>
using namespace std;

int isReversible(int n){
    int rev = 0;
    while(n>0){
        if(rev>INT_MAX)return -1;
        int dig = rev%10;
        rev = rev*10 + dig;
        n/=10;
    }
    return 1;
}

int main(){
    int n;
    cin>>n;
    int res = isReversible(n);
    cout<<res<<endl;
    return 0;
}