/* Given an integer N, now you have to convert all zeros of N to 5.
Input Format
The first Line takes input integer N, denoting the number.
Output Format
Print the number after replacing all 0's with 5.
*/
#include<iostream>
#include<string>
using namespace std;
int convertZeroToFive(int n){
    string nstring=to_string(n);
    for(char &ch:nstring){
        if(ch=='0'){
            ch='5';
        }
    }int result=stoi(nstring);
    return result;
}
int main(){
    int n;
    cin>>n;
    cout<<convertZeroToFive(n);
}