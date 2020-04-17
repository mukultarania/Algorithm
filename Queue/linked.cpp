#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* link;
};
Node* front;
Node* rear;
struct Node* getNode(int i){
    Node* temp = new Node();
    temp->data = i;
    temp->link = NULL;
    return temp;  
}
bool isEmpty(){
    if(rear == NULL && front == NULL){
        return true;
    } else {return false;   }
}
void Enqueue(int data){
    Node* temp = getNode(data);
    temp->data = data;
    temp->link = NULL;
    if(isEmpty()){
       front = rear = temp; 
        return;
    }
    rear->link = temp;
    rear = temp;
}
void Dqueue(){
    Node* temp = front;
    if(isEmpty()){
        cout<<"QUEUE is empty";
    } else {
        front = front->link;
    }
    free(temp);
}
void display(){
    Node* temp = front;
    cout<<"Queue:"<<"\t";
    while(temp != NULL){
        cout<<temp->data<<"\t";
        temp = temp->link;
    }
    cout<<endl;
}
int main(){
    front = rear = NULL;
    for(int i=0; i<5; i++){
        Enqueue(i);
        display();
    }
    Dqueue();
    display();
}