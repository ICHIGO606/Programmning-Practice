//spiral anticlockwise
#include<iostream>
#include<vector>
using namespace std;
void spiralAntiClockwise(vector<vector<int>>&mat,int M,int N){
    int top=0;int bottom=M-1;
    int left=0;int right=N-1;
    vector<int>result;
    while(left<=right&&top<=bottom){
        for(int i=top;i<=bottom;i++){
            result.push_back(mat[i][left]);
        }
        left++;
        for(int i=left;i<=right;i++){
            result.push_back(mat[bottom][i]);
        }
        bottom--;
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                result.push_back(mat[i][right]);
            }
            right--;
        }
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                result.push_back(mat[top][i]);
            }
            top++;
        }
    }
    for(size_t i=0;i<result.size();i++){
        if(i!=0)cout<<",";
        cout<<result[i];
    }
    cout<<",END"<<endl;
}