/*Take an input N, a number. Take N more inputs and store that in an array. Take an input
target, a number
a. Write a recursive function which prints subsets of the array which sum to target.
b. Write a recursive function which counts the number of subsets of the array which sum to
target. Print the value returned.
Input Format
Take an input N, a number. Take N more inputs and store that in an array. Take an input target,
a number
Output Format
Display the number of subsets and print the subsets in a space separated manner.
*/
#include<iostream>
#include<vector>
using namespace std;
void printSubsets(vector<int>&arr,int index,int target,vector<int>&subset){
    if(target==0){
        for(int num:subset){
            cout<<num<<" ";
        }
        
        return;
    }
    if(index>=arr.size()||target<0){
        return;
    }
    subset.push_back(arr[index]);
    printSubsets(arr,index+1,target-arr[index],subset);
    subset.pop_back();
    printSubsets(arr,index+1,target,subset);
}
int countSubsets(vector<int>&arr,int index,int target){
    if(target==0){
        return 1;
    }
    if(index>arr.size()||target<0){
        return 0;
    }
    int include=countSubsets(arr,index+1,target-arr[index]);
    int exclude=countSubsets(arr,index+1,target);
    return include+exclude;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    vector<int>subset;
    printSubsets(arr,0,target,subset);
    cout<<endl<<countSubsets(arr,0,target);
}