#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> perfectSquares;
        int i=1;
        while(i*i<=n){
            perfectSquares.push_back(i*i);
            i++;
        }
        return 0;
    }
    bool isPerfectSquare(int n)
    {
        int sr = sqrt(n);
        return sr * sr == n;
    }
};
int main()
{
    Solution solution;
    cout << solution.numSquares(65);
}