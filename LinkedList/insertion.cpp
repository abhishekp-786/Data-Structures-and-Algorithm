#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtBeg(Node *&node, int val){
    Node *temp = new Node(val);
    if(!node){
        node = temp;
        return;
    }
    temp->next = node;
    node = temp;
}

void insertAtEnd(Node *&node, int val){
    Node *curr = new Node(val);
    if(!node){
        curr = node;
        return;
    }
    Node *temp = node;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = curr;
    return;
}
void insertAtMiddle(Node *&node, int val){
    Node *curr = new Node(val);
    if(!node){
        curr = node;
        return;
    }
    Node *slow = node;
    Node *fast = node;
    Node *prev = NULL;
    while(fast!=NULL && fast->next!= NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    curr->next = prev->next;
    prev->next = curr;
    return;
}

void insertAfterEle(Node *&node, int ele, int val){
    Node *curr = new Node(val);
    if(!node){
        node = curr;
        return;
    }
    if(node->data == val){
        curr->next = node;
        node = curr;
        return;
    }
    else{
        Node *temp = node;
        while(temp->data != ele && temp->next != NULL){
            temp = temp->next;
        }
        curr->next = temp->next;
        temp->next = curr;
        return;
    }
}

void print(Node *node){
    Node *temp = node;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){ 
    Node *node = NULL;
    insertAtBeg(node,20);
    insertAtBeg(node,10);
    insertAtEnd(node,30);
    insertAtEnd(node,40);
    print(node);
    insertAtMiddle(node,50);
    print(node);
    insertAfterEle(node,50,60);
    print(node);
    insertAfterEle(node,40,70);
    print(node);
    return 0;
}