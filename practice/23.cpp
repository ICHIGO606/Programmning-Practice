/*Given a N*N matrix. The task is to find the index of column with maximum sum. That is the
column whose sum of elements are maximum.
Input Format
First line contains the N ,size of the square matrix. Next N lines contains N integers each
denoting the elements of the matrix*/
#include<iostream>
#include<vector>
using namespace std;
pair<int,int> indexColumn(vector<vector<int>>&mat,int n){
    int maxSum=INT_MIN;
    int maxSumColumnIndex=-1;
    for(int j=0;j<n;j++){
        int columnSum=0;
        for(int i=0;i<n;i++){
            columnSum+=mat[i][j];
        }if(columnSum>maxSum){
            maxSum=columnSum;
            maxSumColumnIndex=j;
        }
        
    }
    return {maxSumColumnIndex,maxSum};
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>mat(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    pair<int,int>result=indexColumn(mat,n);
    cout<<result.first +1<<" ";
    cout<<result.second<<endl;

}