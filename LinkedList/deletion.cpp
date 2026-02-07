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

void deleteAtBeg(Node*& node){
    if(!node){
        cout<<"No element present till now"<<endl;
    }
    if(node && !node->next){
        cout<<"Deleted element is: "<<node->data<<endl;
        node = NULL;
        return;
    }
    Node *temp = node;
    cout<<"Deleted element is: "<<temp->data<<endl;
    node = temp->next;
    delete temp;
    return;
}

void deleteAtEnd(Node *& node){
    if(!node){
        cout<<"No element present till now"<<endl;
    }
    if(node && !node->next){
        cout<<"Deleted element is: "<<node->data<<endl;
        node = NULL;
        return;
    }
    Node *temp = node;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node *del = temp->next;
    cout<<"Deleted element is: "<<del->data<<endl;
    temp->next = NULL;
    delete del;
    return;
}

void deleteMiddleEle(Node *& node){
    if(!node){
        cout<<"No element present till now"<<endl;
    }
    if(node && !node->next){
        cout<<"Deleted element is: "<<node->data<<endl;
        node = NULL;
        return;
    }
    Node *slow = node;
    Node *fast = node;
    Node *prev = NULL;
    while(fast!=NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *del = slow;
    cout<<"Deleted ELement is: "<<del->data<<endl;
    prev->next = slow->next;
    delete del;
    return;

}

void deleteAfterEle(Node *&node, int ele){
    if(!node){
        cout<<"No element present till now"<<endl;
    }
    Node *curr = node->next;
    Node *prev = node;
    bool found = false;
    while(curr->next != NULL){
        if(prev->data == ele){
            found = true;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    if(found){
    Node *del = curr;
    cout<<"Deleted Element is: "<<del->data<<endl;
    prev->next = curr->next;
    delete del;
    return;
    }
    else {
        cout<<"Element is not present"<<endl;
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
    insertAtBeg(node,70);
    insertAtBeg(node,60);
    insertAtBeg(node,50);
    insertAtBeg(node,40);
    insertAtBeg(node,30);
    insertAtBeg(node,20);
    insertAtBeg(node,10);
    print(node);

    deleteAtBeg(node);
    print(node);

    deleteAtEnd(node);
    print(node);
    
    deleteMiddleEle(node);
    print(node);

    deleteAfterEle(node,20);
    print(node);

    return 0;
}
