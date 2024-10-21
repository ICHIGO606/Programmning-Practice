/*Remove All Adjacent duplicates in a stringYou are given a string s consisting of lowercase English letters. A duplicate removal consists ofchoosing two adjacent and equal letters and removing them.We repeatedly make duplicate removals on s until we no longer can*/
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
string removeAdjacentDuplicates(string s){
    stack<char>st;
    for(char ch:s){
        if(!st.empty()&&st.top()==ch){
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
int main(){
    string s;
    cin>>s;
    string result=removeAdjacentDuplicates(s);
    cout<<result<<endl;
}