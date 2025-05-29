#include <iostream>
using namespace std;
bool satisfyThisCondition(int j, string &s, const int i, int sum)
{
    if (j == s.size())
        return (sum == i);
    cout << sum << endl;
    for (int k = j + 1; k <= s.size(); k++)
    {
        int part = stoi(s.substr(j, k - j));

        if (satisfyThisCondition(k, s, i, sum + part))
            return true;
    }
    return false;
}
class Solution
{
public:
    int punishmentNumber(int n)
    {
        int result = 0;
        for (int i = 1; i <= n; i++)
        {
            string s = to_string(i * i);
            if (satisfyThisCondition(0, s, i, 0))
                result += i * i;
        }
        return result;
    }
    bool satisfyThisCondition(int j, string &s, const int i, int sum)
    {
        if (j == s.size())
            return (sum == i);
      
        for (int k = j + 1; k <= s.size(); k++)
        {
            int part = stoi(s.substr(j, k - j));

            if (satisfyThisCondition(k, s, i, sum + part))
                return true;
        }
        return false;
    }
};
int main()
{
    Solution solution;
    cout<<solution.punishmentNumber(1000);
}