#include <bits/stdc++.h>
using namespace std;

// Find ttarget element present in the mountain array(ele increase then decrease) or not
// id present find the index of target element in O(logn)

// 2,3,4,5,6,7,8,40,8,7
// 0,1,2,3,4,5,6,7, 8,9

// aproach -> 1stly find peak element (it can be the answer)
// then find in the left half of the peak element and in the right half also


int findPeakIdx(vector<int>&arr){
    int n = arr.size();
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

bool beforePeak(vector<int>&arr, int low, int high, int target){
    while(low <= high){
        int mid = low+(high-low)/2;
        if(arr[mid]==target){
            return true;
        }
        else if(arr[mid]>target)high = mid-1;
        else low = mid+1;
    }
    return false;
}
bool afterPeak(vector<int>&arr, int low, int high, int target){
    while(low <= high){
        int mid = low+(high-low)/2;
        if(arr[mid]==target){
            return true;
        }
        else if(arr[mid]>target)low = mid+1;
        else high = mid-1;
    }
    return false;
}

int main(){
    vector<int>arr = {2,3,4,5,6,7,8,40,8,7};
    int target = 1;
    int n = 10;
    int peak = findPeakIdx(arr);
    if(arr[peak]==target){ // peak element can be the target
        cout<<"Yes"<<endl;
        return 0;
    }
    bool left = beforePeak(arr, 0, peak, target);      // check element before peak element
    bool right = afterPeak(arr, peak+1, n-1, target); // check element after peak element
    if( left || right )cout<<"Yes"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}