//island question
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void dfs(vector<vector<char>>&grid,int x,int y){
    if(x<0||x>grid.size()||y<0||y>grid.size()||grid[x][y]='0'){
        return;
    }
    grid[x][y]='0';
    dfs(grid,x+1,y);
    dfs(grid,x-1,y);
    dfs(grid,x,y+1);
    dfs(grid,x,y-1);
}
int numIslands(vector<vector<char>>&grid){
    if(grid.empty())return 0;
    int m=grid.size();
    int n=grid[0].size();
    int islands=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                islands++;
                dfs(grid,i,j);
            }
        }
    }return islands;
}