#include<iostream>
using namespace std;


struct  Node
{
   int data;
   Node* next;
};



Node* createNode(int value){
    Node* newNode = new Node();
    newNode -> data = value;
    newNode -> next = nullptr;
    return newNode;
}

int main(){
    // //first node
    // Node* first= new Node();
    // first->data=10;
    // first->next=nullptr;

    // // second node 
    // Node* second = new Node();
    // second ->data = 20;
    // second ->next = nullptr;


    // // linking 1st and 2nd node

    // first->next=second;

   
    Node* first = createNode(10);
    first -> next = createNode(20);
    first -> next -> next = nullptr;


    Node* temp = first;
    while(temp != nullptr){
        cout<<temp->data<<"->";
        temp = temp -> next;
    }

    cout << "NULL" << endl;
    return 0;
}