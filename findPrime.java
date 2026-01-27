
// You are given an integer n and you have to find prime pairs whose difference is 6
// ex => 5 11, 7 13, ...
public class findPrime {
    static void findPrimeWithDiff6(int n){
        boolean[]isPrm = new boolean[n+1];

        isPrm[0] = isPrm[1] = false;
        for(int i=2; i<=n; i++){
            isPrm[i] = true;
        }

        for(int i=2; i*i<=n; i++){
            if(isPrm[i]){
                for(int j=i*i; j<=n; j+=i){
                    isPrm[j]=false;
                    }
                }
        }

        for(int i=2; i+6<=n; i++){
            if(isPrm[i] && isPrm[i+6]){
                System.out.println(i+" "+(i+6));
            }
        }
    }
    public static void main(String[]args){
        int n = 15;
        findPrimeWithDiff6(n);
    }
}
