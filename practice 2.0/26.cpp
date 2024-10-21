//graph has a cycle or not
#include<iostream>
#include<vector>
using namespace std;
bool dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&recStack){
    if(!visited[node]){
        visited[node]=true;
        recStack[node]=true;
        for(int neighbour:adj[node]){
            if(!visited[neighbour]&&dfs(neighbour,adj,visited,recStack)){
                return true;
            }else if(recStack[neighbour]){
                return true;
            }
        }
    }recStack[node]=false;
    return false;
}
bool hasCycle(int V,vector<vector<int>>&adj){
    vector<bool>visited(V,false);
    vector<bool>recStack(V,false);
    for(int i=0;i<V;i++){
        if(dfs(V,adj,visited,recStack)){
            return true;
        }
    }return false;
}
