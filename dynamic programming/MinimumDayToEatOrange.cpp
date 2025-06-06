#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
    vector<int> memo;
    int minDays(int n){
        if(n<=1) return 1;
        memo.resize(n+1, -1);
        return dp(n);
    }

    int dp(int n) {
        if(n<=1) return n;
        if(memo[n]!=-1) return memo[n];
        //int one = 1+dp(n-1);
        int two = n%2+1+dp(n>>1);
        int three = n%3+1+dp(n/3);
        return memo[n]=min(two, three);
}

};
int main(){
    Solution solution;
    cout<<solution.minDays(638826798);
}