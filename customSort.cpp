#include <bits/stdc++.h>
using namespace std;

void customSort(vector<int>&arr){
    int n = arr.size()+1;
    // int n = arr.length+1;
    for (int i = 0; i < n-1; i++) {
        int originalVal = arr[i] % n;
        arr[originalVal] += n;
    }
    for (int i = 0; i < n-1; i++) {
        if ((arr[i] / n) >= 2) {
            // System.out.print(i + " ");
            cout<<i<<" ";
        }
    }
}   


int main(){
    vector<int>arr = {2,13,12,3,15,4,2,5,3,4,1,2,2,4,2,3};
    // bubbleSort(arr);,
    // selectionSort(arr);
    // insertionSort(arr);
    customSort(arr);
    cout<<endl;
    for(int i : arr)cout<<i<<" ";
    return 0;
}