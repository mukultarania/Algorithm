#include<iostream>
#include<algorithm>
#include<queue>
#include <stdlib.h>
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
//BFS of Binary Search Tree
void LevelOrder(Node* root){
	if(root == NULL) return;
	queue<Node*> Q;
	Q.push(root);
	while(!Q.empty()){
		Node* current = Q.front();
		Q.pop();
		cout<<current->data<<"\t";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
	}
}
void PreOrder(Node* root){
	if(root == NULL) return;
	cout<<root->data<<"\t";
	PreOrder(root->left);
	PreOrder(root->right);
}
void PostOrder(Node* root){
	if(root == NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<"\t";
}
void InOrder(Node* root){
	if(root == NULL) return;
	InOrder(root->left);
	cout<<root->data<<"\t";
	InOrder(root->right);
	
}
Node* Min(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}
struct Node* Delete(struct Node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			struct Node *temp = Min(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
int main(){
	int number;
	char c = 'y';
	int i;
	int del;
    Node* root = NULL;
    root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root,50);
	root = Insert(root,51);
	while(c != 'n'){
		system("cls");
		cout<<"1 . Search an Element"<<endl;
		cout<<"2 . Find Minimum Element"<<endl;
		cout<<"3 . Find Maximum Element"<<endl;
		cout<<"4 . Find Height of BST"<<endl;
		cout<<"5 . Traversal PreOrder"<<endl;
		cout<<"6 . Traversal InOrder"<<endl;
		cout<<"7 . Traversal Post Order"<<endl;
		cout<<"8 . BFS of BST"<<endl;
		cout<<"9 . Delete Element from BST"<<endl;
		cin>>i;
		switch(i){
			case 1:
			cout<<"Enter number be searched\n";
			cin>>number;
			if(Search(root,number) == true) cout<<"Found\n";
			else cout<<"Not Found\n";
			break;
			case 2:
			cout<<"Minimum Element\t"<<FindMin(root)<<endl;
			break;
			case 3:
			cout<<"Maximum Element\t"<<FindMax(root)<<endl;
			break;
			case 4:
			cout<<"Height\t"<<FindHT(root)<<endl;
			break;
			case 5:
			cout<<"\nPreorder\t"; PreOrder(root);
			break;
			case 6:
			cout<<"\nPostorder\t"; PostOrder(root);
			break;
			case 7:
			cout<<"\nInorder"<<"\t"; InOrder(root);
			break;
			case 8:
			LevelOrder(root);
			break;
			case 9:
			cout<<"Enter Element to delete\n";
			cin>>del;
			Delete(root, del);
			break;
		}
		cout<<"\nContinue..... (y,n)\t";
		cin>>c;
	}	
	
	
	
	
	
}