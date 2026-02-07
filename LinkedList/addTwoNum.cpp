#include <iostream>
using namespace std;
/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single 
digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0
itself. 
*/

/*
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtEnd(Node *&node, int val){
    Node *curr = new Node(val);
    if(!node){
        node = curr;
        return;
    }
    Node *temp = node;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = curr;
    return;
}
/*
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/

Node *addTwoNumers(Node*& node1, Node*& node2){
    if(!node1 && !node2){
        cout<<"No element in any LinkedList"<<endl;
        return NULL;
    }
    else if(!node1){
        return node2;
    }
    else if(!node2)return node1;

    int carry = 0;
    Node *ans = NULL;
    while(node1 !=NULL || node2 != NULL || carry){
        int a = (node1 != NULL)?node1->data : 0;
        int b = (node2 != NULL)?node2->data : 0;
        int sum = a+b+carry;
        int dig = sum%10;
        carry = sum/10;
        insertAtEnd(ans,dig);
        if(node1) node1 = node1->next;
        if(node2) node2 = node2->next;
    }
    return ans;
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
    Node *node1 = NULL;
    Node *node2 = NULL;
    insertAtEnd(node1,2);
    insertAtEnd(node1,4);
    insertAtEnd(node1,3);
    insertAtEnd(node2,5);
    insertAtEnd(node2,6);
    insertAtEnd(node2,4);
    print(node1);
    print(node2);

    Node *res = addTwoNumers(node1, node2);
    print(res);
    return 0;
}
