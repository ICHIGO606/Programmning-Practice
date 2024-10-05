#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string direction="DLRU";
int dr[4]={1,0,0,-1};
int dc[4]={0,-1,1,0};
bool isValid(int row,int col,int n,vector<vector<int>>&maze){
    return row>=0 && col>=0 && row<n && col<n && maze[row][col];
}
void findPath(int row,int col,int n,vector<vector<int>>&maze,vector<string>&ans,string&currpath){
    if(row==n-1&&col==n-1){
        ans.push_back(currpath);
        return;
    }
    maze[row][col]=0;
    for(int i=0;i<4;i++){
        int nextrow=row+dr[i];
        int nextcol=col+dc[i];
        if(isValid(nextrow,nextcol,n,maze)){
            currpath+=direction[i];
            findPath(nextrow,nextcol,n,maze,ans,currpath);
            currpath.pop_back();
        }
    }
    maze[row][col]=1;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>maze(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];;
        }
    }
    vector<string>result;
    string currpath="";
    if(maze[0][0]!=0&&maze[n-1][n-1]!=0){
        findPath(0,0,n,maze,result,currpath);
    }
    sort(result.begin(),result.end());
    if(result.empty()){
        cout<<-1;
    }else{
        for(string &path:result){
            cout<<path<<endl;
        }
    }
}