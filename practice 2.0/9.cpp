//convert 0 to five in a given number
#include<iostream>
#include<string>
using namespace std;
int converZeroToFive(int n){
    string result=to_string(n);
    for(char ch:result){
        if(ch=='0'){
            ch='5';
        }
    }
    int res=stoi(result);
    return res;
}