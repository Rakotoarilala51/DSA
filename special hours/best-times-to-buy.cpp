#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       vector<int> result(n, 0);
       int minimum =prices[1];
       int maximum = 0;
       for(int i=1; i<prices.size(); i++){
            minimum = min(minimum, prices[i]);
            maximum = max(maximum, prices[i]-minimum);
            result[i]=maximum;   
       }
       return result[n-1];
    }
};
int main(){
    Solution solution;
    vector<int> prices = {7,6,4,3,1};
    cout<<solution.maxProfit(prices);
}