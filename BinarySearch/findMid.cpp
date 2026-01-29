#include <bits/stdc++.h>
using namespace std;


// not completed
int findSmlst(vector<int>&arr){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = INT_MAX;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]<arr[high]){
            ans = arr[mid];
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int>arr = {5,6,7,81,1,2,3,4};
    int smallest = findSmlst(arr);
    cout<<smallest<<endl;

    return 0;
}