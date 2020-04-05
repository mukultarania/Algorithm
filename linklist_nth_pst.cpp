#include <iostream>
using namespace std;
struct Node
{
   int data;
   Node* link;
};
struct Node* head;
void insert(int new_data, int n) { 
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
   new_node->data = new_data; 
   new_node->link = NULL; 
   if(n==1){
      new_node->link = head;
      head = new_node;
      return;
   } 
   struct Node* temp2 = (struct Node*) malloc(sizeof(struct Node)); 
   for(int i =0; i<=n-2; i++){
      temp2 = temp2->link;
   }
   new_node->link = temp2->link;
   temp2->link = new_node;
} 
void dis(){
    Node* temp = new Node();
    temp = head;
    while(temp->link != NULL){
        cout<<temp->data<<"\t";
        temp = temp->link;
    }
    
}
void del(int x);
int main(){
    head = NULL;
    insert(1, 1);
    insert(2, 2);
    insert(3, 3);
    insert(4, 4);
    insert(5, 5);
    dis();
    cout<<"sad";
    return 0;
}