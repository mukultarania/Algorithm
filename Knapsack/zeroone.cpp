#include<iostream>
#include<algorithm>
using namespace std;
int max(int i, int j){
    return( i>= j? i: j);
}
int main(){
  int P[5][9] = {0, 1, 2, 5, 6};
  int Wt[5] = {0, 2,3 ,4, 5};
  int m = 8, n = 4;
  int K[5][9];
  for(int i = 0; i<= n ; i++){
      for(int w = 0; w<=m; w++){
          if(i == 0 || w == 0) {
            K[i][w] = 0;
          }
          else if(Wt[i] <= w) {
              K[i][w] = max(P[i] + K[i-1][w- Wt[i]], K[i-1][w]);
              }
          else{
              K[i][w] = K[i-1][w];
          } 
      }
  } 

  cout<<K[n][m]; 
}