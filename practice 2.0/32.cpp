//ropes minimum cost
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int minCost(vector<int>&ropes){
    priority_queue<int,vector<int>,greater<int>>minHeap(ropes.begin(),ropes.end());
    int totalCost=0;
    while(minHeap.size()>1){
        int first=minHeap.top();
        minHeap.pop();
        int second=minHeap.top();
        minHeap.pop;
        int cost=first+second;
        totalCost+=cost;
        minHeap.push(cost);
    }
    return totalCost;
}
