#include <bits/stdc++.h>
using namespace std;

//in a sorted strictly increasing array find the smallest element which is greater than given 
// element (not equal)

int targetPresent(vector<int>&arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==target)return mid;
        else if(arr[mid]>target)high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int findEleInArr(vector<int>&arr, int target){
    int n = arr.size();
    int low = 0, high = n-1; // target should not be the last element otherwise element will not present
    int ans = -1;
    while(low <= high){
        int mid = low+(high-low)/2;
        if(arr[mid]>target){
            ans = arr[mid];
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

int main(){
    vector<int>arr = {2,3,5,6,7,8,9,10,12};

    int n = arr.size();
    int target = 11; // we have to find element just > target
    int tarIdx =  targetPresent(arr,target);
    if( tarIdx != -1){
        if(tarIdx == n-1){
            cout<<"Greater element not present"<<endl;
            return 0;
        }
        else cout<< arr[tarIdx+1] <<endl;
    }
    else{
    int ans = findEleInArr(arr, target);
    if(ans == -1){
        cout<<"Element not presnt"<<endl;
        return 0;
    }
    else{
        cout<< ans <<endl;
    }
    }

    return 0;
}