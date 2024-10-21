//last index in an array
#include<iostream>
#include<vector>
using namespace std;
int lastElement(vector<int>&arr,int M,int index){
    if(index<0){
        return -1;
    }
    if(arr[index]==M){
        return index;
    }
    return lastIndex(arr,M,index-1);
}
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    cout<<lastElement(arr,m,n-1);
}