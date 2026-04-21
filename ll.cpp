#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

int main() {
    
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = NULL;
    
    Node* current = node1;
    while(current != NULL){
        cout << current -> data << " -> ";
        current = current -> next;
    }
    
    
}