#include <bits/stdc++.h>
using namespace std;

// each element present 3 times, one element present 4 times find that element
int freq4eleFind(vector<int>&arr, int n){
    vector<int>temp(32,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<32; j++){
            if(arr[i] & (1 << j))temp[j]++;
        }
    }
    for(int i=0; i<32; i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    int ans = 0;
    int k=0;
    for(int ele : temp){
            ans = ans + ((ele % 3) << k);
            k++;
    }
    return ans;
}

// Given an integer array of n size where present element are [1,n] and every element present once or twice
// return an array of all integers present twice in sorted manner. tc -> o(n) and sc -> o(c)

vector<int>twiceEleArray(vector<int>&arr,int n){
    // tc -> o(n) and sc -> o(n) and unsorted answer
    unordered_map<int,int>mp;
    for(int i : arr){
        mp[i]++;
    }
    vector<int>res;
    for(auto ele : mp){
        if(ele.second >=2 ){
            res.push_back(ele.first);
        }
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // int ans = freq4eleFind(arr,n);
    // cout<<ans<<endl;

    vector<int>res = twiceEleArray(arr,n);
    for(int i : res)cout<<i<<" ";
    cout<<endl;
    return 0;
}