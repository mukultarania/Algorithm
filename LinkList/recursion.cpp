#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* link;
};
void display(struct Node* head){
    if(head == NULL){return;}
    cout<<head->data<<"\t";
    display(head->link);
    //head = head->link;
}
struct Node* reve(struct Node* head){
    struct Node* p = head;
    if(p->link == NULL){
        head = p;
        return head;
    }
    reve(p->link);
    struct Node* temp = p->link;
    temp->link = p;
    p->link = NULL;

}
struct Node* insert(struct Node* head, int new_data) { 
   Node* new_node = new Node(); 
   new_node->data = new_data; 
   new_node->link = head; 
   head = new_node; 
   return head;
}
int main(){
    Node* head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    cout<<"The linked list is: ";
    //display(head);
    head = reve(head);
    display(head);
    return 0;
}