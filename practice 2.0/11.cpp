//if mat[i][j]==1 then rows and colums should be 1
#include<iostream>
#include<vector>
using namespace std;
void modifyMatrix(vector<vector<int>>&mat,int m,int n){
    vector<int>rows(m);
    vector<int>cols(n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
                row[i]=1;
                row[j]=1;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(row[i]==1||col[j]==1){
                mat[i][j]=1;
            }
        }
    }
}