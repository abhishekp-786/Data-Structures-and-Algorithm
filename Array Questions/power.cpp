#include <bits/stdc++.h>
using namespace std;

// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).


int main(){
    int x = 2;
    int n = 8;
    int prod = x;
    for(int i=1; i<n; i++){
        prod*=x;
    }
    cout<<prod<<endl;

    return 0;
}