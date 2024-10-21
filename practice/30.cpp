/*Take as input a 2-d array. Print the 2-D array in spiral form anti-clockwise.
Input Format
Two integers M(row) and N(column) and further M * N integers(2-d array numbers).
Output Format
All M * N integers separated by commas with 'END' written in the end(as shown in example).*/
#include<iostream>
#include<vector>
using namespace std;
void spiralAntiClockWise(vector<vector<int>>&mat,int M,int N){
    int top=0,bottom=M-1;
    int left=0;int right=N-1;
    vector<int>result;
    while(top<=bottom&&left<=right){
        for(int i=top;i<=bottom;i++){
            result.push_back(mat[i][left]);
        }
        left++;
        for(int i=left;i<=right;i++){
            result.push_back(mat[bottom][i]);
        }
        bottom--;
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                result.push_back(mat[i][right]);
            }
            right--;
        }
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                result.push_back(mat[top][i]);
            }
            top++;
        }
    }
    for(size_t i=0;i<result.size();i++){
        if(i!=0)cout<<",";
        cout<<result[i];
    }
    cout<<",END";
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
    spiralAntiClockWise(mat,m,n);
}