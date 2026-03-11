#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> numberOfConsecutiveChar(string s)
    {
        char current = s[0];
        int countOfCurrent = 1;
        vector<int> temp;
        for (int i = 1; i < s.size(); i++)
        {
            if (current == s[i])
                countOfCurrent++;
            else
            {
                temp.push_back(countOfCurrent);
                current = s[i];
                countOfCurrent = 1;
            }
        }
        temp.push_back(countOfCurrent);
        return temp;
    }
    int countBinarySubstrings(string s)
    {
        vector<int> consecutive = this->numberOfConsecutiveChar(s);
        int ans=0;
        for(int i=0; i<consecutive.size()-1; i++){
            ans+=min(consecutive[i], consecutive[i+1]);
        }
        return ans;
    }
};

int main()
{
    string s = "00110011";
    Solution solution;
    cout<<solution.countBinarySubstrings(s);
}