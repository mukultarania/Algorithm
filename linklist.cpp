#include <iostream>
using namespace std;
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
} 
void display() { 
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) { 
      cout<< ptr->data <<"\t"; 
      ptr = ptr->next; 
   } 
} 
int main() { 
   int n;
   cout<<"Enter Length of linklist"<<"\n";
   cin>>n;
   int i[n];
   for(int x = 0; x<n; x++){
      cout<<"Enter a number to insert\n";
      cin>>i[x];
      insert(i[x]);
   }
   // insert(3);
   // insert(1);
   // insert(7);
   // insert(2);
   // insert(9);
   cout<<"The linked list is: ";
   display(); 
   return 0; 
} 