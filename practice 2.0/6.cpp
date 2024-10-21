//maz length concatenated string uniquw characters
#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
int maxLength;
unordered_set<char>charSet;
void backtrack(vector<string>&arr,int index,string current){
    unordered_set<char>currentSet;
    for(char ch:current){
        if(currentSet.count(ch)>0||charSet.count(ch)>0){
            return;
        }
        currentSet.insert(ch);
    }
    maxLength=max(maxLength,static_cast<int>(current.size()));
    for(int i=index;i<arr.size;i++){
        backtrack(arr,i+1,current+arr[i]);
        backtrack(arr,i+1,current);
    }
}
int maxContancenation(vector<string>&arr){
    maxLength=0;
    backtrack(arr,0,"");
    return maxLength;
}