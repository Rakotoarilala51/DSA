#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);
        result[0]=0;
        result[1]=1;
        for(int i=2; i<=n; i++){
            result[i]=result[i/2]+(i&1);
        }
        return result;
    }

};
int main(){
    vector<int> dp;
    Solution solution;
    dp=solution.countBits(5);
    for(int i: dp){
        cout<<i<<" ";
    }
}