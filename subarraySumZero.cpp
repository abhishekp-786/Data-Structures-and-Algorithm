#include <bits/stdc++.h>
using namespace std;

int subArraySumZero(vector<int>&arr){
    int n = arr.size();
    /*
    tc -> o(n^2)
    for(int i=0; i<n; i++){
        int sum = arr[i];
        for(int j=i+1; j<n; j++){
            sum += arr[j];
            if(sum==0){
                cout<<i<<" "<<j<<endl;
                return true;
            }
        }
    }
    */
    // Using set(to store prefix sum so that we can easily track exists sum),
    //  if prefix sum repeats or prefix sum = 0 -> required subarray exists
    // tc = o(n) and sc = o(n)
    unordered_set<int>mp;
    int psum = 0;
    int c=0;
    for(int i = 0; i<n; i++){
        psum += arr[i];
        if(mp.find(psum)!=mp.end() || psum == 0){
            c++;
        }
        mp.insert(psum);
    }
   
    return c;
}

int main(){
    // vector<int>arr = {3,2,-1,4,-3};
    // vector<int>arr = {2,13,12,-27,3,122,4,2,21,-23,3,4,0,21,2,4,2,3,-9};
    vector<int>arr = {3,2,-1,4,-3,-2,5,-5,-3};
    int count = subArraySumZero(arr);
    cout<<count<<" subarrays present whose sum is zero";
    return 0;
}