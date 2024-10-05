//max robbery
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int maxRobbery(vector<int>&houses){
    int n=houses.size();
    if(n==0)return 0;
    if(n==1)return houses[0];
    vector<int>dp(n);
    dp[0]=houses[0];
    dp[1]=max(houses[0],houses[1]);
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],houses[i]+dp[i-2]);
    }
    return dp[n-1];
}
