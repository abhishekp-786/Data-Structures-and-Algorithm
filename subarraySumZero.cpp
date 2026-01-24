#include <bits/stdc++.h>
using namespace std;

bool subArraySumZero(vector<int>&arr){
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

    // Using hashmap(to store prefix sum),
    //  if prefix sum repeats or prefix sum = 0 -> required subarray exists
    unordered_set<int>mp;
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
        if(mp.find(sum)!=mp.end() || sum == 0){
            return true;
        }
        mp.insert(sum);
    }
   
    return false;
}

int main(){
    vector<int>arr = {3,2,-1,4,-3};
    bool isSumZero = subArraySumZero(arr);
    if(isSumZero){
        cout<<"YES";
    }
    else cout<<"NO";
    return 0;
}