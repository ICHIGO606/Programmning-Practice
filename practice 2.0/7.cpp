//brackets paranthsis all valid combination for n//
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
void generateParanthesis(int open,int close,string current,vector<int>&result){
    if(open==0&&close==0){
        result.push_back(current);
        return;
    }
    if(open>0){
        generateParanthesis(open-1,close,current+'(',result);
    }
    if(close>open){
        generateParanthesis(open,close-1,currrent+')',result);
    }
}