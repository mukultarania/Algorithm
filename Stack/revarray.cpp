#include<iostream>
#include<conio.h>
#include<stack>
using namespace std;
void Reverse(char *C, int n){
    stack<char> S;
    //pushing elements into stack
    for(int i=0; i<n; i++){
        S.push(C[i]);
    }
    for(int i=0; i<n; i++){
        C[i] = S.top();
        S.pop();
    }

}
void display(char *C){
    for(int i = 0; i<51; i++){
        cout<<C[i];
    }
}
int main(){
    char C[51] = "Hello World";
    Reverse(C, strlen(C));
    display(C);
    getch();
}
