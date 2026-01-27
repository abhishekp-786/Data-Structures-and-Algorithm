#include <bits/stdc++.h>
using namespace std;

// Fins the max len of subarray who has equal number of 0's and 1's

void findSubarray(vector<int>&arr){
    int n = arr.size();
    // brute Force o(n^2) and sc = o(1)
    /*
    int ans = 0;
    for(int i=0; i<n-1; i++){
        int c0 = 0, c1 = 0;
        for(int j=i; j<n; j++){
            if(arr[j]==0)c0++;
            if(arr[j]==1)c1++;

            if(c0==c1){
                ans = max(ans, j-i+1);
            }
        }
    }
    */
    // tc = o(n) and sc = o(n)
    unordered_map<int,int>mp;
    int ans = 0;
    mp[0]=-1;
    int c0 = 0, c1 = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==0)c0++;
        if(arr[i]==1)c1++;
        int diff = c1 - c0;

        if(mp.find(diff)!=mp.end()){
            c++;
            ans = max(ans, i-mp[diff]);
        }
        else mp[diff] = i;
    }
    cout<<ans<<endl;
}

int main(){

    vector<int>arr = {1,0,1,1,0,0,1,0,1,1,0,0,1,0,0};
    // vector<int>arr = {0,0,0,1,1,0,1};
    findSubarray(arr);
    return 0;
}