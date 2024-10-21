/*Q3. check graph is bipartite
There is an undirected graph with n nodes, where each node is numbered between 0
and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that
node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge
between node u and node v. The graph has the following properties:
➔ There are no self-edges (graph[u] does not contain u).
➔ There are no parallel edges (graph[u] does not contain duplicate values).
➔ If v is in graph[u], then u is in graph[v] (the graph is undirected).
➔ The graph may not be connected, meaning there may be two nodes u and v such
that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B
such that every edge in the graph connects a node in set A and a node in set B.
Input:
First line contains two integers V and E which represent the number of vertex
and number of edges in directed graph respectively.
Next all lines contains two integers v1 and v2 which represent the two vertex
and edge between it.
Output:
print true or false (graph is bipartite or not)*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
bool isBipartite(vector<vector<int>>&nums,int V){
    vector<int>color(V,-1);
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            queue<int>q;
            q.push(i);
            color[i]=0;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int neighbour:nums[node]){
                    if(color[neighbour]==-1){
                        color[neighbour]=1-color[node];
                        q.push(node);
                    }else if(color[neighbour]==color[node]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>>graph(V);
    for(int i=0;i<E;i++){
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    if(isBipartite(graph,V)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}