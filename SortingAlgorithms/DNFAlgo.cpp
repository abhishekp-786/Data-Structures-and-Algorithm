#include <bits/stdc++.h>
using namespace std;


// Dutch National Flag(DNA) algorithm is used to sort where element is only 0,1,2 present
// and it is unstable sorting algo (as it does not preserve the order of same element
//  as they were in the original array)
// it is an in-place sorting algorithm

void DNFSort(vector<int>&arr){
    int n = arr.size();
    int low = 0, high = n-1;

    int mid = 0;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low++],arr[mid++]);
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high--]);
        }
    }
}

int main(){
    vector<int>arr = {1,2,0,0,1,2,0,1,2,2,2,1,1,0,1,0,2};

    DNFSort(arr);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}