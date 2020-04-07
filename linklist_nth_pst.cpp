#include <iostream>
using namespace std;
struct Node
{
   int data;
   Node* link;
};
struct Node* head = NULL;
void display();
void insert(int new_data, int n) { 
    
   Node* temp1 = new Node();
   temp1->data = new_data; 
   temp1->link = NULL; 
   if(n == 1){
      temp1->link = head;
      head = temp1;
      display();
      return;
   } 
   Node* temp2 = head; 
   for(int i =0; i<=n-2; i++){
      temp2 = temp2->link;
   }
   temp1->link = temp2->link;
   temp2->link = temp1;
   display();
} 
void remove(int n){
   Node* temp1 = head;
   for(int i; i<n-2 ; i++){
      temp1 = temp1->link;
   }
   Node* temp2 = temp1->link;
   temp1->link = temp2->link;
   free(temp2);
   display();
}
void display(){
   Node* temp = head;
   cout<<"List is"<<"\t";
   while(temp != NULL){
        cout<<temp->data<<"\t";
        temp = temp->link;
   }
   cout<<"\n";
    
}
int main(){
   insert(1, 1);
   insert(2, 1);
   insert(3, 1);
   insert(4, 1);
   insert(5, 1);
   remove(2);
   
    return 0;
}