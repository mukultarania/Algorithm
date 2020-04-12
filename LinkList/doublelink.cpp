#include<iostream>
using namespace std;
void display();
struct Node{
    int data;
    Node* pre;
    Node* next;
};
struct Node* head = NULL;
struct Node* getNewNode(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->pre = NULL;
    temp->next = NULL;
    return temp;
}
void insert(int data){
    Node* temp = getNewNode(data);
    if(head == NULL){
        head = temp;
        return;
    }
    head->pre = temp;
    temp->next = head;
    head = temp;
    
}
void display(){
   Node* temp = head;
   cout<<"Link List is\t";
   while(temp != NULL){
       cout<<temp->data<<"\t";
       temp = temp->next;
   }
   cout<<"\n";
}

void revDisplay(){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    cout<<"Reverse Linked List is\t";
    while(temp != NULL){
       cout<<temp->data<<"\t";
       temp = temp->pre;
    }
   cout<<"\n";
}
int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    display();
    revDisplay();
    
}