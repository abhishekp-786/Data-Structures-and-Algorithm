#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>&arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        int mnIdx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[mnIdx]){
                mnIdx = j;
            }
        }
        swap(arr[i],arr[mnIdx]);
    }
}

vector<int>twoSum(vector<int>&arr,int target){
    int n = arr.size();
    //Using  hashmap -> tc=o(n) and sc = o(n)
    /*
    unordered_map<int,int>mp;
    for(int i =0; i<n; i++){
        int diff = target-arr[i];
        if(mp.find(diff)!=mp.end()){
            return {mp[diff],i};
        }
        mp[arr[i]] = i;
    }
    
    */

    // using two pointer approach (for sorted array)
    /* tc->O(n) and sc -> O(c)
    int left = 0, right = n-1;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum==target){
            return {left,right};
        }
        else if(sum < target)left++;
        else right--;
    }
    */
    return {-1,-1};
    
}

int main(){
    vector<int>arr = {2,3,4,6,7,8,4,2,8,7,5,4,5};
    selectionSort(arr);
    int target = 15;
    vector<int>res = twoSum(arr,target);
    for(int i : res)cout<<i<<" ";
    return 0;
}