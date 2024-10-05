//mpst frequent element in a string
#include<iostream>
#include<string>
#include<unordered_map>
char mostFrequent(string &s){
    unordered_map<char,int>freqMap;
    for(char ch:s){
        freqMap[ch]++;
    }
    char maxFreq=s[0];
    int maxFrequency=freqMap[s[0]];
    for(auto &entry:freqMap){
        if(entry.second>maxFrequency){
            maxFrequency=entry.second;
            maxFreq=entry.first;
        }
    }return maxFreq;
}
