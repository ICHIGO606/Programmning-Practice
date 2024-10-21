/*There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e.,
grid[0][0]).
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only
move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can
take to reach the bottom-right corner.
Input Format
Two integers M(row) and N(column).
Output Format
Print the total number of unique paths can be formed*/
#include<iostream>
#include<vector>
using namespace std;
int findUniquePaths(int m,int n){
    vector<vector<int>>dp(m,vector<int>(n,1));
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }return dp[m-1][n-1];
}
int main(){
    int m;
    int n;
    cin>>m>>n;
    cout<<findUniquePaths(m,n);
}