/*Q16. Maximum Length of a Concatenated String with Unique Characters
Description:
You are given an array of strings arr. A string s is formed by the concatenation of
a subsequence of arr that has unique characters.
Return the maximum possible length of s.
A subsequence is an array that can be derived from another array by deleting some or no
elements without changing the order of the remaining elements.*/
#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
int maxLength;
unordered_set<char>char_set;
void backtrack(vector<string>&arr,int index,string current){
    unordered_set<char>currentSet;
    for(char ch:current){
        if(currentSet.count(ch)>0||char_set.count(ch)>0){
            return;
        }
        currentSet.insert(ch);
    }
    maxLength=max(maxLength,static_cast<int>(current.size()));
    for(int i=index;i<arr.size();i++){
        backtrack(arr,i+1,current+arr[i]);
        backtrack(arr,i+1,current);
    }
}
int maxContancenation(vector<string>&arr){
    maxLength=0;
    backtrack(arr,0,"");
    return maxLength;
}
int main(){
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxContancenation(arr);

}