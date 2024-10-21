//nthFibonacci
#include<iostream>
using namespace std;
long long nfibonacci(int n){
    if(n<=1)return n;
    long long prev2=0;
    long long prev1=0;
    long long current;
    for(int i=2;i<n;i++){
        current=prev1+prev2;
        prev2=prev1;
        prev1=current;
    }
    return current;
}