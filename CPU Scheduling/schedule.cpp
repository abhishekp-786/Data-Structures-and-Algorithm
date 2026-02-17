#include <iostream>
using namespace std;

int size = 0;

class Node{
    public:
    int val;
    Node *next;
    Node *prev;
    Node(int val){
        this->val = val;
        next = prev = NULL;
    }
};

class sdl{
    Node *head;
    Node *tail;
    sdl(){
        head = tail = NULL;
    }
    unordered_map<int, Node>mp;

    void insertAtEnd(int val){
        Node *curr = new Node(val);

        if(!head){
            head = tail = curr;
            return;
        }
        
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
        size++;
    }
};


void addNodeAtEnd(Node *&node, int val){
    Node *temp = new Node(val);
    if(!node){
        node = temp;
        return;
    }
    
    temp->prev = tail

}


int main(){

    return 0;
}