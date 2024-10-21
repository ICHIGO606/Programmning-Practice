//max column sum index and sum of a matrix
#include<iostream>
#include<vector>
using namespace std;
pair<int,int> maxColumnSum(vector<vector<int>>&mat,int n){
    int maxSum=INT_MIN;
    int maxColumnIndex=-1;
    for(int j=0;j<n;j++){
        int columnSum=0;
        for(int i=0;i<n;i++){
            columnSum+=mat[i][j];
            if(columnSum>maxSum){
                maxSum=columnSum;
                maxColumnIndex=j;
            }
        }
    }
    return {maxColumnIndex,maxSum};
}