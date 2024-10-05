//is graph bipartite
#include<iostream>
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
                    }else if(color[neighbour]==color[node]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}