#include <bits/stdc++.h>
using namespace std;

// Print all subsequences of the array elements using bit manipulation
void printAllSubSeq(vector<int>&arr){
    int n = arr.size();
    
    for(int mask=0; mask < (1<<n); mask++){
        for(int j=0; j<n; j++){
            if(mask & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    vector<int>arr = {1,2,3};
    printAllSubSeq(arr);
    return 0;
}