//most frequent element in a string
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
char maxFrequency(string &s){
    unordered_map<char,int>freqMap;
    for(char ch:s){
        freqMap[ch]++;
    }
    char maxFreq=s[0];
    int maxfrequency=freqMap[s[0]];
    for(auto& entry:freqMap){
        if(entry.second>maxfrequency){
            maxfrequency=entry.second;
            maxFreq=entry.first;
        }
    }
    return maxFreq;
}
int main(){
    string s;
    cin>>s;
    char result=maxFrequency(s);
    cout<<result;
}