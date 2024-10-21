/*Take as input N, a number. Print odd numbers in decreasing sequence (up until 0) and
even numbers in increasing sequence (up until N) using Recursion
Input Format
Take as input N
Output Format
Print odd numbers in decreasing sequence (up until 0) and even numbers in increasing
sequence (up until N*/
#include<iostream>
using namespace std;
void decreasingOdd(int n){
    if(n<1){
        return;
    }
    if(n%2!=0){
        cout<<n<<endl;
    }
    decreasingOdd(n-1);
}
void increasingEven(int current,int n){
    if(current>n){
        return;
    }
    if(current%2==0){
        cout<<current<<endl;
    }
    increasingEven(current+1,n);
    
}
int main(){
    int n;
    cin>>n;
    decreasingOdd(n);
    increasingEven(1,n);
}