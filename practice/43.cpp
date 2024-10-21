/*Connect RopesGiven an array of integers A representing the length of ropes.You need to connect these ropes into one rope. The cost of connecting two ropes is equal to thesum of their lengths.Find and return the minimum cost to connect these ropes into one rope*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minCost(vector<int>&ropes){
    priority_queue<int,vector<int>,greater<int>>minHeap(ropes.begin(),ropes.end());
    int totalCost=0;
    while(minHeap.size()>1){
        int first=minHeap.top();
        minHeap.pop();
        int second=minHeap.top();
        minHeap.pop();
        int cost=first+second;
        totalCost+=cost;
        minHeap.push(cost);
    }
    return totalCost;
}
int main(){
    int n;
    cin>>n;
    vector<int>ropes(n);
    for(int i=0;i<n;i++){
        cin>>ropes[i];
    }
    int cost=minCost(ropes);
    cout<<cost;
}