#include <bits/stdc++.h>
using namespace std;

bool canEat(vector<int>&arr, int m, int marker){
    int sum = 0;
    for(int ele : arr){
        if(ele>marker)
        sum+=(ele-marker);
    }
    return sum>=m;
}

int markerPoint(vector<int>&arr, int m){
    int low = 1;
    int high = INT_MIN;
    for(int i : arr)high = max(high,i);
    int ans =0;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(canEat(arr, m, mid)){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    return ans;
}

int main(){
    // vector<int>arr = {10,40,20,30};
    vector<int>arr = {5,8,20,1};
    int m = 16;
    int ans = markerPoint(arr,m);
    cout<<ans<<endl;
    return 0;
}
