/*You are a professional robber planning to rob houses along a street. Each house has a certain
amount of money stashed, the only constraint stopping you from robbing each of them is that
adjacent houses have security systems connected and it will automatically contact the police if
two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house,
Input Format
First line contains a Integers ‘N’ which represents the size of house array.
Second line contains all the N elements of the house array
Output Format
Print the maximum amount of money you can rob tonight without alerting the police*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int maxRob(vector<int>&nums){
    int n=nums.size();
    if(n==0)return 0;
    if(n==1)return nums[0];
    vector<int>dp(n);
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
    }
    return dp[n-1];
}
int main(){
    int n;
    cin>>n;
    vector<int>houses(n);
    for(int i=0;i<n;i++){
        cin>>houses[i];
    }
    int result=maxRob(houses);
    cout<<result<<endl;
}