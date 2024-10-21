/*Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's
(water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands
horizontally or vertically. You may assume all four edges of the grid are all surrounded
by water.
Input:
First line contains two integers m and n which represent the number of rows
and number of columns in 2D binary grid respectively.
Next all lines contains all elements of matrix.
Output:
Print integer which represent the number of islands in 2D grid
*/
#include<vector>
#include<iostream>
using namespace std;
void dfs(vector<vector<char>>&grid,int x,int y){
    if(x<0||x>=grid.size()||y<0||y>=grid.size()||grid[x][y]=='0'){
        return;
    }
    grid[x][y]='0';
    dfs(grid,x,y-1);
    dfs(grid,x,y+1);
    dfs(grid,x-1,y);
    dfs(grid,x+1,y);
}
int numIslands(vector<vector<char>>&grid){
    if(grid.empty())return 0;
    int m=grid.size();
    int n=grid[0].size();
    int numislands=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                ++numislands;
                dfs(grid,i,j);
            }
        }
    }
    return numislands;
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<char>>grid(m,vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    int result=numIslands(grid);
    cout<<result<<endl;
}