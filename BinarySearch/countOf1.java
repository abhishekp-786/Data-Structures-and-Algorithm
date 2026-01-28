package BinarySearch;


// 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0  count number of 1's in O(logn)
class countOf1{
    static int countOccuranceOfOne(int[]arr){
        int n = arr.length;

        int low = 0, high = n-1; // Applying binary search in opposite manner

        int ans = -1;

        while(low <= high){
            int mid = low + (high - low )/2;
            if(arr[mid]==1){
                ans = mid;
                low = mid+1;
            }
            else if(arr[mid]==0){
                high = mid-1;
            }
        }
        return ans+1;

    }
    public static void main(String[]args){
        int[]arr = {1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0};
        int countOnes = countOccuranceOfOne(arr);
        System.out.println(countOnes);
    }
}