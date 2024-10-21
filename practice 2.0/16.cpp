#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    for(int ch=0;ch<s.size();ch++){
        if(ch%2==0){
            s[ch]+=1;
        }else{
            s[ch]-=1;
        }
    }cout<<s;
}
