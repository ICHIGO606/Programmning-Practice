#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int minSets(vector<int>&arr){
    unordered_map<int,int>m;
    int n=arr.size();
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    vector<int>temp;
    int sz=n;
    int ret=0;
    unordered_map<int,int>::iterator it=m.begin();
    while(it!=m.end()){
        temp.push_back(it->second);
        it++;
    }
    sort(temp.rbegin(),temp.rend());
    for(int i=0;i<temp.size();i++){
        if(sz<=n/2)break;
        ret++;
        sz-=temp[i];
    }
    return ret;
}
int main(){
    vector<int> v = {3,3,3,3,5,5,5,2,2,7};
    cout<<minSets(v);
}