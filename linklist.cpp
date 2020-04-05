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
// void insert_at(int new_data, int n) { 
//    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
//    new_node->data = new_data; 
//    new_node->next = NULL; 
//    if(n==1){
//       new_node->next = head;
//       head = new_node;
//       return;
//    } 
//    struct Node* temp2 = (struct Node*) malloc(sizeof(struct Node)); 
//    for(int i =0; i<=n-2; i++){
//       temp2 = temp2->next;
//    }
//    new_node->next = temp2->next;
//    temp2->next = new_node;
//     cout<<"The linked list is: ";
//    display();
// } 
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
   int n;
   cout<<"Enter Length of linklist"<<"\n";
   cin>>n;
   int i[n];
   for(int x = 0; x<n; x++){
      cout<<"Enter a number to insert\n";
      cin>>i[x];
      insert(i[x]);
   }
   return 0; 
} 