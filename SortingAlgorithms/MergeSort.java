package SortingAlgorithms;
public class MergeSort {
    /* 
    public static void mergeTheArray(int[]arr, int low, int mid, int high){
        int n1 = mid-low + 1;
        int n2 = high-mid;
        int []leftArray = new int[n1];
        int []rigthArray = new int[n2];

        for(int i=0; i<n1; i++){
            leftArray[i] = arr[low+i];
        }
        for(int i=0; i<n2; i++){
            rigthArray[i] = arr[mid+1+i];
        }

        int i = 0, j = 0, k = low;
        while(i<n1 && j< n2){
            if(leftArray[i] < rigthArray[j]){
                arr[k] = leftArray[i];
                i++;
            }
            else{
                arr[k] = rigthArray[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            arr[k] = leftArray[i];
            k++;
            i++;
        }
        while(j<n2){
            arr[k] = rigthArray[j];
            k++;
            j++;
        }
    }
    public static void mergeSort(int[]arr,int low, int high){
        if(low < high){
            int mid = low+(high-low)/2;
            mergeSort(arr,low,mid);
            mergeSort(arr, mid+1, high);

            mergeTheArray(arr, low, mid, high);
        }
    }
*/
    static void merge(int[]arr, int low, int mid, int high){
        int tsize = high-low+1; // temp array size
        int[]temp = new int[tsize];
        int i = low, j = mid+1, k = 0;

        while(i<=mid && j<=high){
            if(arr[i]<arr[j]){
                temp[k++] = arr[i++];
            }
            else temp[k++] = arr[j++];
        }
        while(i<=mid){
            temp[k++] = arr[i++];
        }
        while(j<=high){
            temp[k++] = arr[j++];
        }
        for(int p=0; p<temp.length; p++){
            arr[low+p] = temp[p];
        }

    }
    static void mergeSort(int[]arr, int low, int high){
        if(low<high){
            int mid = low+(high-low)/2;
            mergeSort(arr,low,mid);
            mergeSort(arr,mid+1,high);
            merge(arr,low,mid,high);
        }
    }
    public static void main(String[] args){
        int[]arr = {2,13,12,3,122,4,2,21,3,4,0,21,2,4,2,3};
        int n = arr.length;
        mergeSort(arr,0,n-1);
        for(int i : arr){
            System.out.print(i+" ");
        }
    }
}
