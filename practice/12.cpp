/*Find next greater element
We are given a circular array, print the next greater number for every element. If it is
not found print -1 for that number. To find the next greater number for element Ai
,
start from index i + 1 and go uptil the last index after which we start looking for the
greater number from the starting index of the array since array is circular.
Input:
First line contains the length of the array n. Second line contains the n space separated
integers.
Output:
Print n space separated integers each representing the next greater element.*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextGreaterElement(vector<int>&nums){
    int n=nums.size();
    vector<int>result(n,-1);
    stack<int>st;
    for(int i=0;i<2*n;i++){
        while(!st.empty()&& nums[st.top()]<nums[i%n]){
            result[st.top()]=nums[i%n];
            st.pop();
        }
        if(i<n){
            st.push(i);
        }
    }
    return result;
}
int main(){
    vector<int>nums={1,2,3};
    vector<int>result=nextGreaterElement(nums);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}
