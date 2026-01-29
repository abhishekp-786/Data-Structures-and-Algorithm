#include <bits/stdc++.h>
using namespace std;

/*
You are given a 0-indexed 2D integer matrix grid of size n * n with values in 
the range [1, n2]. Each integer appears exactly once except a which appears twice
and b which is missing. The task is to find the repeating and missing numbers a and b.
Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.
*/

vector<int> findRepAndMiss(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    int k = m*n;
    vector<int>temp(k,0);
    int ans1 = 0, ans2 = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(temp[grid[i][j]-1]!=0)ans1 = grid[i][j];
            temp[grid[i][j]-1] = grid[i][j];
        }
    }
    for(int i=0; i<k; i++){
        if(temp[i]==0){
            ans2 = i+1;
            break;
        }
    }
    return {ans1, ans2};
}

int main(){
    vector<vector<int>>grid = {{9,1,7},{8,9,2},{3,4,6}};
    vector<int>res = findRepAndMiss(grid);
    cout<<"Missing number is: "<< res[1] <<" and Repeated number is: "<< res[0] <<"\n";
    return 0;
}