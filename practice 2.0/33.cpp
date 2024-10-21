//stock span problem
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int>stockSpan(vector<int>&prices){
    int n=prices.size();
    vector<int>span(n);
    stack<int>st;
    span[0]=1;
    s.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty()&&prices[st.top()]<=prices[i]){
            st.pop();
        }
        span[i]=(s.empty())?(i+1):i-s.top();
        s.push(i);
    }
    return span;
}