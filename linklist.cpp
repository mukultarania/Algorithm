#include <iostream>
using namespace std;
void display();
struct Node { 
   int data; 
   struct Node *next; 
}; 
struct Node* head = NULL;   
void insert(int new_data) { 
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
   new_node->data = new_data; 
   new_node->next = head; 
   head = new_node; 
    cout<<"The linked list is: ";
   display();
} 
void display() { 
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) { 
      cout<< ptr->data <<"\t"; 
      ptr = ptr->next; 
   } 
   cout<<"\n";
} 
int main() { 
   insert(1);
   insert(1);
   insert(1);
   insert(1);
   insert(1);
   insert(1);
   return 0; 
} 