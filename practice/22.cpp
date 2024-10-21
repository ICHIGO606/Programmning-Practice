/*3.Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j]
is 1 (or true) then make all the cells of ith row and jth column as 1.
Input Format
First line contains two integers m and n denoting the dimensions of the matrix Next m lines
contain n integers each.
*/
#include<iostream>
#include<vector>
using namespace std;
void modifyMatrix(vector<vector<int>>&mat,int m,int n){
    vector<int>row(m,0);
    vector<int>col(n,0);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
                row[i]=1;
                col[j]=1;
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
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>mat(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    modifyMatrix(mat,m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}