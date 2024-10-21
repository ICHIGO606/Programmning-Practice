//max Jump in an array
#include<iostream>
#include<vector>
using namespace std;
bool maxJump(vector<int>&nums){
    int n=arr.size();
    int maxreach=0;
    for(int i=0;i<n;i++){
        if(i>maxreach){
            return false;
        }
        maxreach=max(maxreach,i+nums[i]);
    }
    return maxreach>=n-1;
}
