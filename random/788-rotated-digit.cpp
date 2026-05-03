#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isGoodInteger(int number){
        unordered_map<int, int> validNumber{
            {0,0},
            {1,1},
            {2,5},
            {5,2},
            {6,9},
            {9,6},
            {8,8},
        };
        int temp = number;
        int rotatedNumber=0, puissance=0;
        while(temp){
            int digit= temp%10;
            if(validNumber.find(digit)==validNumber.end()) return false;
            digit=validNumber[digit];
            rotatedNumber+=(digit*(int(pow(10,puissance))));
            puissance++;
            temp/=10;
        }
        cout<<rotatedNumber<<endl;
        return rotatedNumber!=number;
    }
    int rotatedDigits(int n) {
        vector<int> dp(n+1, 0);
        for(int i=1; i<=n; i++){
            dp[i]=dp[i-1]+isGoodInteger(i);
            cout<<i<<": "<<isGoodInteger(i)<<endl;
        };
        cout<<endl;
        return dp[n-1];
    }
};
int main(){
    Solution solution;
    cout<<solution.isGoodInteger(10);
}