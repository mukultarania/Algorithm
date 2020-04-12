#include <iostream>
using namespace std;
#define MAX_SIZE 101 
class Stack{
    protected:
    int A[MAX_SIZE];
    

    public:
    int top;
    Stack(){
        top = -1;
    }
    void push(int x){
        if(top == MAX_SIZE-1){ 
            return;
        }
        A[++top] = x;
    }
    void pop(){
        if(top == -1){
            return;
        }
        top--;
    }

    bool isEmpty(){
        if(top == -1){
            cout<<"Stack is EMPTY"<<endl;
            return true;
        } else { return false;}
    }

    void Print() {
		int i;
		printf("Stack: ");
		for(i = 0;i<=top;i++)
			printf("%d ",A[i]);
		printf("\n");
	}

    void Top(){
        cout<<"Top\t"<<A[top]<<endl;
    }

};

void main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.Print();
    s.pop();
    s.Print();
}