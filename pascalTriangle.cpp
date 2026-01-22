#include <bits/stdc++.h>
using namespace std;

vector<int>pascalTri(int n){
    n++;
    vector<vector<int>>arr;
    arr.push_back({1});
    arr.push_back({1,1});

    int k = 3;
    while(k<=n){
        vector<int>temp(k);
        temp[0]=1;
        for(int j=1; j<k-1; j++){
            temp[j] = arr[k-2][j-1]+arr[k-2][j];
        }
        temp[k-1]=1;
        arr.push_back(temp);
        k++;
    }
    return arr[n-1];
}

int main(){
    int n=5;
    // o(n^2) -> Brute force
    vector<int>res = pascalTri(n);
    for(int i : res){
        cout<<i<<" ";
    }

    cout<<endl;

    //  o(n) -> Optimize(formula based)
    int ans = 1;
    for(int i=0; i<=n; i++){
        cout<<ans<<' ';
        ans = ans*(n-i)/(i+1);
    }

    return 0;
}