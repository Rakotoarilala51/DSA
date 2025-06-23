#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
bool checkGroup(vector<vector<string>> groups){
    set<string> grp;
    for(auto grpaw:groups){
        for(string univ:grpaw){
            if(grp.count(univ)) return false;
            grp.insert(univ);
        }
    }
    return true;
}


int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<string>> groups(n);

    for (int i = 0; i < n; i++) {
        groups[i].resize(4);

        string groups_row_temp_temp;
        getline(cin, groups_row_temp_temp);

        vector<string> groups_row_temp = split(rtrim(groups_row_temp_temp));

        for (int j = 0; j < 4; j++) {
            string groups_row_item = groups_row_temp[j];

            groups[i][j] = groups_row_item;
        }
    }
    if(checkGroup) cout<<"YES";
    else cout<<"NO";
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
