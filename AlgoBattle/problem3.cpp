#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
int countSetBit(int n){
    int count=0;
    while(n){
        if(n&1) count+=1;
        n>>=1;
    }
    return count;
}


int main()
{
    freopen("input.txt", "r", stdin);
    string R_temp;
    getline(cin, R_temp);

    int R = stoi(ltrim(rtrim(R_temp)));
    vector<int> scoreBoard;
    vector<string> name; 
    vector<pair<int, string>> lead;
    multimap<string, int> inf;

    for (int R_itr = 0; R_itr < R; R_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        string Name = first_multiple_input[0];

        string Score = first_multiple_input[1];
        name.push_back(Name);
       int score;
        if(Score=="NOTHING") score=0;

        else{
             score=stoi(Score);
        } 
        pair<int, string> core={score, Name};
        
        lead.push_back(core);
       
    }
    sort(lead.begin(), lead.end());
    for(pair p: lead){
        cout<<p[0]<<p[1]<<endl;
    }

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