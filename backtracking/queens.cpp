#include<iostream>
#include<vector>
using namespace std;
int N;
void printSol(vector<vector<int>>board){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isSafe(int row,int col,vector<bool>rows,vector<bool>leftDiagnol,vector<bool>rightDiagnol){
    if(rows[row]==true||leftDiagnol[row+col]==true||rightDiagnol[col-row+N-1]==true){
        return false;
    }
    return true;
}
bool solve(vector<vector<int>>&board,int col,vector<bool>rows,vector<bool>&leftDiagnol,vector<bool>&rightDiagnol){
    if(col>=N){
        return true;
    }
    for(int i=0;i<N;i++){
        if (isSafe(i,col,rows,leftDiagnol,rightDiagnol)){
            rows[i]=true;
            leftDiagnol[i+col]=true;
            rightDiagnol[col-i+N-1]=true;
            board[i][col]=1;
            if(solve(board,col+1,rows,leftDiagnol,rightDiagnol)){
                return true;
            }
            rows[i]=false;
            leftDiagnol[i+col]=false;
            rightDiagnol[col-i+N-1]=false;
            board[i][col]=0;
        }
        
    }
    return false;
}
int main(){
    cin>>N;
    vector<vector<int>>board(N,vector(N,0));
    vector<bool>rows(N,false);
    vector<bool>leftDiagnol(2*N-1,false);
    vector<bool>rightDiagnol(2*N-1,false);
    if(solve(board,0,rows,leftDiagnol,rightDiagnol)){
        printSol(board);
    }else{
        cout<<"Sol does not exist "<<endl;
    }
    return 0;
}