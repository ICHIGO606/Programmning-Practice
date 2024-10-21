/*You are given an integer array nums. You are initially positioned at the array's first index, and
each element in the array represents your maximum jump length at that position.
Input Format
First line contains a Integers ‘N’ which represents the size of nums array.
Second line contains all the N elements of the nums array
Output Format
Print true if you can reach the last index, or false otherwise.*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool maxJump(vector<int>&nums){
    int maxReach=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(i>maxReach){
            return false;
        }
        maxReach=max(maxReach,i+nums[i]);
    }
    return maxReach>=n-1;
}
int main(){
    int n;
    cin>>n;
    vector<int>jump(n);
    for(int i=0;i<n;i++){
        cin>>jump[i];
    }
    bool ans=maxJump(jump);
    cout<<ans<<endl;   
}