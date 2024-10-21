//toggle string
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    for( int ch=0;ch<s.size();ch++){
        if(s[ch]>='A'&&s[ch]=<'Z'){
            s[ch]=s[ch]+('a'-'A')
        }
        else if(s[ch]>='a'&&s[ch]=<'z'){
            s[ch]=s[ch]+('A'-'a');
        }
    }
    cout<<s;
}