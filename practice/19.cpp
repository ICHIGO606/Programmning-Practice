/*Take as input N, the size of the array. Take N more inputs and store that in an array. Take
as input M, a number. Write a recursive function which returns the last index at which M is found
in the array and -1 if M is not found anywhere. Print the value returned.
Input Format
Enter a number N and add N more numbers to an array, then enter number M to be searched
Output Format
Display the last index at which the number M is found*/
#include<iostream>
#include<vector>
using namespace std;
int lastIndex(vector<int>&nums,int M,int index){
    if(index<0){
        return -1;
    }
    if(nums[index]==M){
        return index;
    }
    return lastIndex(nums,M,index-1);
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int M;
    cin>>M;
    cout<<lastIndex(nums,M,n-1);
}