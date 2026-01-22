# include <iostream>
using namespace std;

int main(){

    // A
    // B C
    // C E F H
    // I J K L O

    // int n = 5;
    // int st = 'A';
    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<i; j++){
    //         cout<<char(st++)<<" ";
    //     }
    //     cout<<endl;
    // }

    // Diamond pattern
    int n = 3;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            cout<<" ";
        }
        for(int j=0; j<2*i+1; j++){
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<=i; j++)
        cout<<" ";
        
        for(int j=0; j<2*(n-i)-3; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}