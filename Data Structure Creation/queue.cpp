#include<bits/stdc++.h>
using  namespace std;

class Queue{
    public:
    int n;
    Queue* next;
    Queue(int data){
        n = data;
        next = NULL;
    }
    Queue();
};

void push(Queue*& node, int n){
    Queue *curr = new Queue(n);
    if(!node){
        node = curr;
        return;
    }
    Queue* temp = node;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = curr;
}
void pop(Queue*& node){
    if(!node){
        cout<<"No element present"<<"\n";
        return;
    }
    Queue *temp = node;
    cout<<temp->n<<endl;
    node = temp->next;
    delete temp;
    return;
}

int front(Queue* node){
    return node->n;
}

int back(Queue* node){
    Queue* temp = node;
    while(temp->next != NULL)temp = temp->next;
    return temp->n;
}

int size(Queue* node){
    int c = 0;
    Queue* temp = node;
    while(temp!=NULL){
        c++;
        temp = temp->next;
    }
    return c;
}
bool isEmpty(Queue* node){
    return node == NULL;
}

void print(Queue*& node){
    Queue* temp = node;
    while(temp != nullptr){
        cout<<temp->n<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main(){
    Queue *dq = nullptr;
    cout<<boolalpha<<isEmpty(dq)<<endl;
    push(dq,5);
    push(dq,6);
    push(dq,7);
    push(dq,8);
    push(dq,9);
    push(dq,10);
    print(dq);
    // pop(dq);
    // print(dq);
    cout<<front(dq)<<endl;
    cout<<back(dq)<<endl;
    cout<<size(dq)<<endl;
    pop(dq);
    cout<<size(dq)<<endl;
    push(dq,11);
    cout<<size(dq)<<endl;
    cout<<boolalpha<<isEmpty(dq)<<endl;

    return 0;
}