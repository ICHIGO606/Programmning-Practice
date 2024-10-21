/*26 .Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.
Input Format
First line contains a single integer N. Next N lines contain N space separated integers.
Output Format
Print N lines with N space separated integers of the rotated array.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotateAntiClockWise(vector<vector<int>>&mat){
    int n=mat.size();
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-i-1;j++){
            int temp=mat[i][j];
            mat[i][j]=mat[j][n-1-i];
            mat[j][n-1-i]=mat[n-1-i][n-1-j];
            mat[n-1-i][n-1-j]=mat[n-1-j][i];
            mat[n-1-j][i]=temp;
        }
    }
    
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
    rotateAntiClockWise(mat);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}