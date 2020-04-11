#include<iostream>
using namespace std;
void display();
struct Node{
    int data;
    Node* pre;
    Node* next;
};
struct Node* head = NULL;
void insert(int data){
    Node* temp = new Node();
    Node* temp2 = head;
    temp->data = data;
    if(head == NULL){
        temp->next = NULL;
        temp->pre = head;
    } else {
        temp->next = temp2;
        temp2->pre = temp;
    }
    head = temp;
    display();
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
int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    
}