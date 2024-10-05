/*Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
The output strings should be printed in the sorted order considering '(' has higher value than ')'.
Input Format
Single line containing an integral value 'n'.
Output Format
Print the balanced parentheses strings with every possible solution on a new line.
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void generateParanthesis(int open,int close,string current,vector<string>&result){
    if(open==0&&close==0){
        result.push_back(current);
        return;
    }
    if(open>0){
        generateParanthesis(open-1,close,current+'(',result);
    }
    if(close>open){
        generateParanthesis(open,close-1,current+')',result);
    }
}
int main(){
    int n;
    cin>>n;
    vector<string>result;
    generateParanthesis(n,n,"",result);
    sort(result.begin(),result.end());
    for(string &s:result){
        cout<<s<<endl;
    }
}