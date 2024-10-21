/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check
whether it contains any cycle or not.
Input:
First line contains two integers V and E which represent the number of vertex
and number of edges in directed graph respectively.
Next all lines contains two integers v1 and v2which represent the two vertex
and edge between it.
Output:
Print true or false (graph has cycle or not)
*/
#include<iostream>
#include<vector>
using namespace std;
bool dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&recStack){
    if(!visited[node]){
        visited[node]=true;
        recStack[node]=true;
        for(int neighbour:adj[node]){
            if(!visited[neighbour]&& dfs(neighbour,adj,visited,recStack)){
                return true;
            }
            else if(recStack[neighbour]){
                return true;
            }
        }
    }
    recStack[node]=false;
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
int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>>adj(V);
    for(int i=0;i<E;i++){
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
    }
    if(hasCycle){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}