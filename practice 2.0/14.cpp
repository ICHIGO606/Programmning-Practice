//rotate matrix anti clockwise 90 degrees
#include<iostream>
#include<vector>
using namespace std;
void rotateAntiClockWise(vector<vector<int>>&mat){
    int n=mat.size();
    for(int i=0;i<n/2;i++){
        for(j=i;j<n-i-1;j++){
            int temp=mat[i][j];
            mat[i][j]=mat[j][n-i-1];
            mat[j][n-i-1]=mat[n-i-1][n-j-1];
            mat[n-i-1][n-j-1]=mat[n-j-1][i];
            mat[n-j-1][i]=temp;
        }
    }
}