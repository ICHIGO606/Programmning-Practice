//check palindrome string
#include<iostream>
#include<string>
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