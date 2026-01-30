#include <bits/stdc++.h>
using namespace std;


// not completed
int findSmlst(vector<int>&arr){
    int n = arr.size();
    int low = 0, high = n-1;
    while(low < high){
        int mid = low+(high-low)/2;
        if(arr[mid]>arr[high]){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    return arr[low];
}

int main(){
    vector<int>arr = {10,12,1,4,5,6,8};
    int smallest = findSmlst(arr);
    cout<<smallest<<endl;

    return 0;
}