#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;
bool solve(vector<string> &hints, unordered_map<char, int> gems)
{
    for (string hint : hints)
    {
        stringstream ss(hint);
        char gem1, gem2;
        string position;
        ss >> gem1 >> position >> gem2;
        if (position == ">")
        {
            if (gems[gem1] <= gems[gem2])
                return false;
        }
        else if (position == "<")
        {
            if (gems[gem1] >= gems[gem2])
                return false;
        }

        else if (position == "<>")
        {
            if (abs(gems[gem2] - gems[gem1]) != 1)
                return false;
        }
        else if (position == ">>>")
        {
            if (gems[gem1] != (int)gems.size() - 3)
                return false;
        }
        else if (position == ">>")
        {
            if (gems[gem1] != (int)gems.size() - 2)
                return false;
        }
        else if (position == "<<<")
        {
            if (gems[gem1] != 2)
                return false;
        }
        else if (position == "<<")
        {
            if (gems[gem1] != 1)
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    cin.ignore();
    vector<string> hints;
    while (t--)
    {
        string hint;
        getline(cin, hint);
        hints.push_back(hint);
    }
    string gems;
    getline(cin, gems);
    unordered_map<char, int> pos;
    for (int i = 0; i < gems.size(); i++)
    {
        pos[gems[i]] = i;
    }
    if (solve(hints, pos))
        cout << "CORRECT";
    else
        cout << "INCORRECT";
    return 0;
}