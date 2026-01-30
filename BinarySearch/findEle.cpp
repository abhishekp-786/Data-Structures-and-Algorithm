#include <bits/stdc++.h>
using namespace std;

int findEle(vector<int>&arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low+(high-low)/2;
        if(arr[mid]==target)return mid;     // 4 9 10 12 18 1 2
        if(arr[low]<=arr[high]){             // 0 1  2  3  4 5 6
            if(target >= arr[low] || target < arr[mid]){
                high = mid-1;
            }
            else if(target<arr[mid]){
                low = mid+1;
            }
        }
        else{ 
            if(arr[mid]<target && target<=arr[high]){
                low = mid+1;
            }
            else high = mid-1;
        }
    }
    return -1;
}

int main(){

    vector<int>arr = {10,12,13,1,4,5,6,8};
    // vector<int>arr = {4,8,16,18,12};
    // vector<int>arr = {4,9,10,12,13,18,1,2};
    int target = 13;
    int idx = findEle(arr, target);
    cout<< idx <<endl;

    return 0;
}