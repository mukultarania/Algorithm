#include<iostream>
#include<algorithm>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* getNode(int i, Node* root){
    Node* temp = new Node();
    temp->data = i;
    temp->left = temp->right = NULL;
    return temp;
}

//Insert Element in BST
Node* Insert(Node* root, int data){
if(root == NULL){
        root = getNode(data, root);
    } else if(data <= root->data){
        root->left = Insert(root->left, data);
    } else{
        root->right = Insert(root->right, data);
    }
    return root;
}

//Searching a data in BST
bool Search(Node* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}

// Finding Min and Max Element
int FindMin(Node* root){
	if(root == NULL) return -1;
	else if(root->left == NULL) return root->data;
	return FindMin(root->left);
}
int FindMax(Node* root){
	if(root == NULL) return -1;
	else if(root->right == NULL) return root->data;
	return FindMax(root->right);
}
int FindHT(Node* root){
	if(root == NULL) return -1;
	return( max(FindHT(root->left), FindHT(root->right)) +1);
}
int main(){
    Node* root = NULL;
    root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root,50);
	root = Insert(root,51);
	// Ask user to enter a number.  
	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(Search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
	cout<<"Minimum Element\t"<<FindMin(root)<<endl;
	cout<<"Maximum Element\t"<<FindMax(root)<<endl;
	cout<<"Height\t"<<FindHT(root)<<endl;
}