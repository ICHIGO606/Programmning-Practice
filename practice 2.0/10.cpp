//increasing even and decreasing odd to anumber
#include<iostream>
using namespace std;
void decreasingOdd(int n){
    if(n<1){
        return;
    }
    if(n%2!=0)cout<<n<<" ";
    decreasingOdd(n-1);
}
void increasingEven(int current,int n){
    if(current>n){
        return;
    }
    if(current%2==0){
        cout<<current<<" ";
    }
    increasingEven(current+1,n);
}
