#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> letter;
int getValue(string& s, int pos){
    if(isdigit(s[pos])) return s[pos]-'0';
    for(int len=3; len<=5 && pos+len<=s.size(); len++){
        string substring=s.substr(pos, len);
        if(letter.count(substring)) return letter[substring];
    }
    return -1;

}
int sol(){
    string digit;
    cin>>digit;
    vector<int> allDigit;
    for(int i=0; i<digit.size(); i++){
        int dig=getValue(digit, i);
        if(dig!=-1) allDigit.push_back(dig);
    }
    return allDigit.front()*10+allDigit.back();
}
string solve()
{
    string digit, result = "";
    char leftDigit = '\0', rightDigit = '\0';
    cin >> digit;
    int left = 0;
    for (int right = 0; right < digit.size(); right++)
    {

    }

    result.push_back(leftDigit);
    result.push_back(rightDigit);
    return result;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, sum = 0;
    letter = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
    cin >> t;
    while (t--)
    {
        sum+=sol();
    }
    cout << sum << endl;
}