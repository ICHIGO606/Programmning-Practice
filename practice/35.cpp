/*Given a number n, print n-th Fibonacci Number.
Nth term= (N-1)th term + (N-2)th term*/
#include<iostream>
using namespace std;
long long nthFibonacci(int n){
    if(n<=1)return n;
    long long prev2=0;
    long long prev1=1;
    long long current;
    for(int i=2;i<=n;i++){
        current=prev1+prev2;
        prev2=prev1;
        prev1=current;
    }
    return current;
}
int main(){
    int n;
    cin>>n;
    long long result=nthFibonacci(n);
    cout<<result<<endl;
}