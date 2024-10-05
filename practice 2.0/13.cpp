//print and count subsets
#include<iostream>
#include<vector>
using namespace std;
void printSubsets(vector<int>&arr,int target,int index,vector<int>&subset){
    if(target==0){
        for(int num:subset){
            cout<<num<<" ";
        }
    }
    if(index>arr.size()||target<0){
        return;
    }
    subset.push_back(arr[index]);
    printSubsets(arr,target-arr[index],index+1,subset);
    subset.pop_back();
    printSubsets(arr,target,index+1,subset);    
}
int countSubsets(vector<int>&arr,int index,int target){
    if(target==0)return 1;
    if(index>arr.size()||target<0)return 0;
    int include=countSubsets(arr,index+1,target-arr[index]);
    int exclude=countSubsets(arr,index+1,target);
    return include+exclude;
}
