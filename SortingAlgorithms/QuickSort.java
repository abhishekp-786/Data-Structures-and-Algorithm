package SortingAlgorithms;

// QuickSort is an divide and conquer algorithm
// it takes each element one by one and keep that element at its right position
// i.e, every element smaller than pivot goes to left of pivot and every element greater than 
// pivot will go right side of pivot
// tc => o(n^2) if every time pivot is selected largest or smallest element (i.e; if array is already sorted)
// tc => o(nlogn) if pivot divides the array in two halves
// sc => O(n) due to an unbalanced partitioning

class QuickSort{
static void swap(int[]arr,int i, int j){
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
static int partition(int[]arr, int low, int high){
    int pivot = arr[high];

    int i = low-1;
    for(int j=low; j<=high; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,high);
    return i+1;
}
static void quickSort(int[]arr, int low, int high){
    if(low<=high){
        int pivotIdx = partition(arr,low,high);
        quickSort(arr, low, pivotIdx-1);
        quickSort(arr, pivotIdx+1,high);
    }
}

    public static void main(String[]args){
        int[]arr = {2,13,12,3,122,4,2,21,3,4,0,21,2,4,2,3};
        int n = arr.length;
        quickSort(arr,0,n-1);
        for(int i : arr){
            System.out.print(i+" ");
        }

    }
}