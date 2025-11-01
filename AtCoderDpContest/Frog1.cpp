#include <bits/stdc++.h>
using namespace std;
class Solution{
    vector<int> costarica;
public:
    int frog(vector<int> cost) {
        int n=cost.size()-1;
        this->costarica=cost;
        return dp(0, 0, n);
    }
private:
    int dp(int i, int cost, int &n){
        cout<<costarica[i]<<" "<<cost<<endl;
        if(i==n) return cost;
        int ans = INT_MAX;
        ans = min(ans, dp(i+1, cost+abs(costarica[i]-costarica[i+1]), n));
        if(i+2<=n) ans = min(ans, dp(i+2, cost+abs(costarica[i]-costarica[i+2]), n));
        return ans;
        
    }
};

int main()
{
    vector<int> cost = {10,10};
    Solution solution;
    
    cout<<solution.frog(cost);
}