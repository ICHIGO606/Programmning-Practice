/*Take as input S, a string. Write a function that returns true if the string is a palindrome and
false otherwise. Print the value returned*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool checkPalindrome(string s){
    int left=0;
    int right=s.size()-1;
    while(left<right){
        if(s[left]!=s[right]){
            return false;
        }else{
            left++;
            right--;
        }
    }return true;
}
int main(){
    string s;
    cin>>s;
    bool ans=checkPalindrome(s);
    cout<<ans;
    
}