//remove adjacent duplicates of a string
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
string removeAdjacentDuplicates(string&s){
    stack<char>st;
    for(char ch:s){
        if(!st.empty()&&st.top==ch){
            st.pop();
        }else{
            st.push(ch);
        }
    }
    string result;
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    reverse(result.begin(),result.end());
    return result;
}
