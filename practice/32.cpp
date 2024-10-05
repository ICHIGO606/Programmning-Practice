/* Heapy the array
You are given an array , your task is to rearrange the whole array so it can form a
max heap order
Input Format
First line contains an Integer N which represents the size of array.
Second line contains all the N elements of the array
Output Format
Print the max heap order of the array .*/
#include<iostream>
#include<vector>
using namespace std;
void maxHeapify(vector<int>&arr,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        maxHeapify(arr,n,largest);
    }
}
void buildMaxHeap(vector<int>&arr,int n){
    for(int i=n/2-1;i>=0;i--){
        maxHeapify(arr,n,i);
    }
}
void printSol(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;  
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    buildMaxHeap(arr,n);
    printSol(arr);
}