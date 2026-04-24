#include <bits/stdc++.h>
using namespace std;

struct Node{
  
    string data;
    Node* next;
    
};

class LinkedList {
    
    private:
    Node *head;
    
    public:
    LinkedList(){
        head = NULL;
    }
    
    void pushFront(string Chara){
        Node *newNode = new Node{Chara, head};
        head = newNode;
    }
    
    void pushBack(string Chara){
        Node * newNode = new Node{Chara, NULL};
        
        if (head == NULL){
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
    
    void dele(string Chara){
        if(head == NULL) return;
        
        if(head -> data == Chara){
            Node* del = head;
            head = head -> next;
            delete del;
            return;
        }
        
        Node* temp = head;
        while(temp -> next != NULL && temp -> next -> data != Chara){
            temp = temp -> next;
        }
        if(temp -> next != NULL){
            Node *del = temp -> next;
            temp -> next = del -> next;
            delete del;
        }
    }
    
    bool search(string Chara){
        Node* temp = head;
        while( temp != NULL){
            if(temp -> data == Chara) return true;
            temp = temp -> next;
        }
        return false;
    }
    
    void printlist() {
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << "[NO PROFILE NAME]\n";
    }
    
    
};

int main() {
    
    LinkedList list;
    
    int n;
    cout << "How many profiles:     ";
    cin >> n;
    
    int index = 1;
    
    while(n--){
        
        
        string some_text;
        cout << "Character " << index << "\n";
        cout << "The Name:      ";
        cin >> some_text;
        
        list.pushBack(some_text);
        index++;
        
    }
    
    cout << "Want to Edit? [Y: Yes, N: NO]\n";
    char choice;
    cin >> choice;
    
    while(choice == 'Y'){
        
       
        cout << "What do you want to do?\n";
        cout << "C: Create New Profile\n";
        cout << "D: Delete Name\n";
        
        
        char cmd;
        cin >> cmd;
        
        if(cmd == 'C'){
            cout << "New Profile:   ";
            string name;
            cin >> name;
            list.pushFront(name);
        }
        
        if(cmd == 'D'){
            
            cout << "Delete Profile:    ";
            string del;
            cin >> del;
            list.dele(del);
            
        }
        
        cout << "Current Profiles:  \n";
        
        list.printlist();
        
        
        cout << "Want to Edit Again? [Y: Yes, N: NO]\n";
        cin >> choice;
        
    }
    
     list.printlist();
    
    
    return 0;
}