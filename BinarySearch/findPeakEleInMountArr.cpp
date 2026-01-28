#include <bits/stdc++.h>
using namespace std;


// You are given an integer mountain array arr of length n where
// the values increase to a peak element and then decrease.
// Return the index of the peak element.
// Your task is to solve it in O(log(n)) time complexity.

int findPeakIdx(vector<int>&arr){
    int n = arr.size();

    // LinearSearch -> tc=o(n);
    /*
    for(int i=1; i<n-1; i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            return i;
        }
    }
    return n-1;

    */

    // Binary Search approach
    // 2 3 4 5 6 7 8 40 8 7
    int low = 1, high = n-2; // because 1st and last element can not be the peak element
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]> arr[mid+1]){
            return mid;
        }
        else if(arr[mid]>arr[mid-1]){
            low = mid+1;
        }
        else if(arr[mid]>arr[mid+1]){
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int>arr = {2,3,4,5,6,7,8,40,8,7};
    // vector<int>arr = {0,10,5,2};
    int idx = findPeakIdx(arr);
    cout<< arr[idx] <<endl;
    return 0;
}