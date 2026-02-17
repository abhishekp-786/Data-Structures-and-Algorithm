#include <bits/stdc++.h>
using namespace std;

// Implement stack using Queue and pop opn should be in O(1)

queue<int>q1;
queue<int>q2;
int sz = 0;

void push(int val){
    q2.push(val);
    
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1,q2);
}

void pop(){
    if(!q1.empty()){
        cout<<"Deleted element is: "<<q.front()<<endl;
        q.pop();
        return ;
    }
    else{
        cout<<"Stack is empty!"<<endl;
        sz--;
        return;
    }
}
void print(){
    if(!q1.empty()){
      cout<<q.front()<<endl;
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    print();
    return 0;
}