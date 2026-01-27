package SortingAlgorithms;


// HeapSort takes o(logn) extra space but it can be o(1) for iterative implementation( in-place algo)
// tc -> O(nlogn) suitable for large i/p
// log(n) factor comes from the height of binary heap
// HeapSort is 2-3 times slower than well-implemeted QuickSort and reason for it's slowness is
// lack of locality of reference
// HeapSort is costly compared to MergeSort as the constants are higher, 
// even tc for both of them is nlogn

public class HeapSort {
    static void swap(int[]arr, int i, int j){
        arr[i] = arr[i]+arr[j];
        arr[j] = arr[i]-arr[j];
        arr[i] = arr[i]-arr[j];

    }
    static void heapify(int[]arr, int n, int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;

        if(left < n && arr[left]>arr[largest]){
            largest = left;
        }
        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }

        if(largest != i){
            swap(arr,i,largest);
            heapify(arr, n, largest);
        }
    }

    static void heapSort(int[]arr){
    int n = arr.length;
    
    for(int i=n/2-1; i>=0; i--){
        heapify(arr,n,i);
    }

    for(int i=n-1; i>0; i--){
        swap(arr,0,i);
        heapify(arr,i,0);
    }
}
    public static void main(String[]args){
        int[]arr = {2,13,12,3,122,4,2,21,3,4,0,21,2,4,2,3};
        heapSort(arr);
        for(int i : arr){
            System.err.print(i+" ");
        }

    }
}
