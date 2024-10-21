// #include<iostream>
// using namespace std;
// bool iskbitset(unsigned int x,unsigned int k){
//     return (x&(1<<(k-1)))?true:false;
// }
// bool isPalindrome(unsigned int x){
//     int l=1;
//     int r=sizeof(unsigned int)*8;
//     while(l<r){
//         if(iskbitset(x,l)!=iskbitset(x,r)){
//             l++,r--;
//             return false;
//         }
//     }
//     return true;
// }
#include <iostream>
using namespace std;

bool isBinaryPalindrome(int n) {
    int reversed = 0;
    int original = n;

    // Reverse the binary representation of n
    while (n > 0) {
        reversed = (reversed << 1) | (n & 1);
        n >>= 1;
    }

    // Check if the reversed binary representation is the same as the original
    return original == reversed;
}
int main() 
{ 
    int x=1; 
    cout << isBinaryPalindrome(x) << endl; 
    
} 