/*You are given an integer array coins representing coins of different
denominations and an integer amount representing a total amount of money.
You may assume that you have an infinite number of each kind of coin.
Input Format
First line contains Two Integers ‘N’ which represents the size of coins array and ‘Amount’ which
represents the total money you need to make .
Second line contains all the N elements of the coins array
Output Format
Print the fewest number of coins that you need to make up that amount. If that amount
of money cannot be made up by any combination of the coins, Print -1.*/
#include<iostream>
#include<vector>
using namespace std;
int coinChange(vector<int>&coins,int amount){
    vector<int>dp(amount+1,amount+1);
    dp[0]=0;
    for(int coin:coins){
        for(int j=coin;j<=amount;j++){
            dp[j]=min(dp[j],dp[j-coin]+1);
        }
    }
    return dp[amount]>amount?-1:dp[amount];
}
int main(){
    int n;
    cin>>n;
    vector<int>coins(n);
    int amount;
    cin>>amount;
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int  result=coinChange(coins,amount);
    cout<<result<<endl;
}