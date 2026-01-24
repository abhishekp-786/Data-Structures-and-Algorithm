#include <bits/stdc++.h>
using namespace std;

//Optimized bubble sort algorithm o(n^2)
// o(n) if already sorted
// sc = o(n)
void bubbleSort(vector<int>&arr){
    int n = arr.size();

    bool sorted = true;

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                sorted = false;
            }
        }
        if(sorted)break;
    }
}

// selection sort, selects min value idx(in second loop) then swap it with curr element(through idx)
// o(n^2) and sc = o(c)
void selectionSort(vector<int>&arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        int mnIdx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[mnIdx]){
                mnIdx = j;
            }
        }
        swap(arr[i],arr[mnIdx]);
    }
}

// for each element in array, find its correct place in previously sorted part of the array
// tc -> O(n) and sc -> O(c)
void insertionSort(vector<int>&arr){
    int n = arr.size();
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        swap(arr[j+1],key);
    }
}

int main(){
    vector<int>arr = {2,13,12,3,122,4,2,21,3,4,0,21,2,4,2,3};
    sort(arr.begin(),arr.end());
    // bubbleSort(arr);,
    // selectionSort(arr);
    // insertionSort(arr);    
    
    for(int i : arr)cout<<i<<" ";
    return 0;
}