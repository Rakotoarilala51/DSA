#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string n;
    string s;
    int lim;
    int x;
    int memo[150][2];
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s){
        this->s = s;
        this->lim = limit;
        return count(finish)-count(start-1);
    }
    long long count(long long _n){
        this->n = to_string(_n);
        if(s.size()>n.size()) return 0;
        memset(memo, -1, sizeof(memo));
        this->x = n.size() - s.size();       
        return dp("",0, 1);
    }
    long long dp(string res, int index, bool last){
        if (index == n.size())
        {   
            //cout<<res<<endl;
            if (res.substr(x, n.size()) == s){
                //cout<<res<<endl;
                return 1;
            }              
            return 0;
        }
        int till = last ? min(lim, n[index]-'0'):lim;
        int ans = 0;
        for (int digit = 0; digit <= till; digit++){    
            ans += dp(res+to_string(digit), index + 1, last && digit == till);
        }
        return ans;
    }
};
int main()
{
    Solution solution;
    string s = "10";
    long long start =15, finish = 2500;
    int limit = 6;
    cout << solution.numberOfPowerfulInt(start, finish, limit, s);
}