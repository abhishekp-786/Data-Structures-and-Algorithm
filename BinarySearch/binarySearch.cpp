#include <bits/stdc++.h>
using namespace std;

int findEle(vector<int>&arr, int target){
    int n = arr.size();

    int low = 0, high = n-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid]==target)return mid;
        else if(arr[mid]<target)low = mid+1;
        else high = mid-1;
    }
    return -1;
}

void findIdx(vector<int>&arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans2 = 0, ans1 = n;
    while(low<=high){
        int mid = low+(high - low)/2;
        if(arr[mid]==target){
            ans1 = mid;
            high = mid-1; 
        }
        else if(arr[mid]>target){
            high  = mid-1;
        }
        else low = mid+1;
    }
    low = 0, high = n-1;

    while(low<=high){
        int mid = low+(high - low)/2;
        if(arr[mid]==target){
            ans2 = mid;
            low = mid+1; 
        }
        else if(arr[mid]>target){
            high  = mid-1;
        }
        else low = mid+1;
    }

    cout<<ans1<<" "<<ans2<<endl;
}

int main(){

    // vector<int>arr = {2,3,4,5,6,7,8,9,12,23,34,54};
    // int idx = findEle(arr,12);
    // cout<<"Element is present at index: "<<idx<<endl;

     vector<int>arr = {1,2,3,3,5,5,5,5,5,5,5,8,8,8,9,9};
     findIdx(arr,2); // find index pair where target presnt first time and last time

    return 0;
}