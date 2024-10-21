/*Trapping rain water
Given N non-negative integers representing an elevation map where the width of each
bar is 1, compute how much water it can trap after raining.
Input:
First line contains a integer N represents the length of array.
Second line contains all N elements of array
Output:
Print total water trapped inside array*/
#include<iostream>
#include<vector>
using namespace std;
int waterTrap(vector<int>&height){
    int n=height.size();
    int left=0;int right=n-1;
    int leftMax=0;int rightMax=0;int waterTrapped=0;
    while(left<=right){
        if(height[left]<=height[right]){
            if(height[left]>leftMax){
                leftMax=height[left];
            }else{
                waterTrapped+=leftMax-height[left];
            }
            left++;
        }else{
            if(height[right]>rightMax){
                rightMax=height[right];
            }else{
                waterTrapped+=rightMax-height[right];
            }
            right--;
        }
    }
    return waterTrapped;
}
int main(){
    int n;
    cin>>n;
    vector<int>height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    cout<<waterTrap(height);
}