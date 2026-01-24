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
// return an array of all integers present twice. tc -> o(n) and sc -> o(c)

void twiceEleArray(vector<int>&arr,int n){
    // tc -> o(n) and sc -> o(n)
    // unordered_map<int,int>mp;
    // for(int i : arr){
    //     mp[i]++;
    // }
    // vector<int>res;
    // for(auto ele : mp){
    //     if(ele.second >=2 ){
    //         res.push_back(ele.first);
    //     }
    // }
    // return res;

    // tc -> o(n) and sc -> o(1)
    for(int i=0; i<n; i++){
        if(arr[abs(arr[i])-1]<0)cout<<abs(arr[i])<<" ";
        arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
    }
}

int main(){
    // int n;
    // cin>>n;
    // vector<int>arr(n);
    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }             
                    //  {0,1,2,3,4,5}
    // vector<int>arr = {5,5,3,1,2,1,4,4,7,8};
                    //  {0,1,2,3,4,5,6,7,8,9}
    // vector<int>arr = {-1,-8,-2,3,7,1,-5,-3,4,5};
    // vector<int>arr = {1,8,2,3,7,1,5,3,4,5};
    vector<int>arr = {17,16,17,12,1,10,2,3,4,5,10,11,2,16,8,7,6,7,11,18};
                    // {17,16,10,2,11,7}

    // int ans = freq4eleFind(arr,n);
    // cout<<ans<<endl;
    twiceEleArray(arr,20);
    // vector<int>res = twiceEleArray(arr,n);
    // for(int i : res)cout<<i<<" ";
    // cout<<endl;
    return 0;
}