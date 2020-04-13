#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* link;
};
struct Node* top = NULL;
struct Node* getNode(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->link = NULL;
    return temp;
}
void push(int data){
    Node* temp = getNode(data);
    temp->link = top;
    top = temp;
}
void pop(){
    if(top==NULL){
        cout<<"Stack is empty"<<endl;
        return;
    }
    Node* temp = top;
    top = temp->link;
    free(temp); 
}
void display(){
    Node* temp = top;
    cout<<"Elements of stack are"<<endl;
    while(temp != NULL){
        cout<<temp->data<<"\t";
        temp = temp->link;
    }
    cout<<endl;
}
int main(){
    top = NULL;
    push(1);
    push(2);
    push(1);
    push(2);
    push(1);
    push(2);
    push(1);
    push(2);
    push(1);
    push(2);
    
    display();
}