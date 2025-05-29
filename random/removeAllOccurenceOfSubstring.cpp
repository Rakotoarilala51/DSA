#include <iostream>
using namespace std;
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        string stack = "";
        for (int i = 0; i < s.size(); i++)
        {
            stack.push_back(s[i]);
            if (stack.length() >= part.length() && stack.substr(stack.length() - part.length(), part.size()) == part)
            {
                stack.resize(stack.size() - part.size());
            }
        }
        return stack;
    }
};
int main()
{
    string s = "eemckxmckxl", part = "emckx";
    Solution solution;
    cout << solution.removeOccurrences(s, part);
}