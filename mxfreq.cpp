#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)cin>>arr[i];
    int mx =1;
    int ele = arr[0];
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;

        if(mp[arr[i]]>= mx){
            ele = arr[i];
            mx = mp[arr[i]];
        }
    }
    
    cout<<ele<<endl;
    return 0;
}