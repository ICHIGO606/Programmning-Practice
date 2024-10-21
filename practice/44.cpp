/*STOCK SPAN PROBLEMThe stock span problem is a financial problem where we have a series of n daily price quotesfor a stock and we need to calculate the span of stocks price for all n days.The span Si of the stocks price on a given day i is defined as the maximum number ofconsecutive days just before the given day, for which the price of the stock on the given day isless than or equal to its price on the current day.*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> calculateSpan(vector<int>&prices){
    int n=prices.size();
    vector<int>span(n);
    stack<int>s;

    span[0]=1;
    s.push(0);
    for(int i=1;i<n;i++){
        while(!s.empty()&&prices[s.top()]<=prices[i]){
            s.pop();
        }
        span[i]=(s.empty())?(i+1):(i-s.top());
        s.push(i);
    }
    return span;
}
int main(){
    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    vector<int>span=calculateSpan(prices);
    for(int i=0;i<n;i++){
        cout<<span[i]<<" ";
    }
}