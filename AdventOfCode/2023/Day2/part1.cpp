#include<bits/stdc++.h>
using namespace std;
bool solve1(string s){
    stringstream ss(s);
    string token;
    while(getline(ss, token, ';')){
        unordered_map<string, int> sets;
        stringstream sss(token);
        int quantity;
        string color;
        while(sss>>quantity>>color){
            if(!color.empty() && color.back()==',') color.pop_back();
            sets[color]+=quantity;
        }
        if(sets["red"]>12 || sets["green"]>13 || sets["blue"]>14) return false;
    }
    return true;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string line;
    int i=1;
    int sum=0;
    while (getline(cin, line))
    {
        string input=line.substr(8);
        if(solve1(input)) sum+=i;
        i++;
    }
    cout<<sum<<endl;
    cout<<i;
    return 0;
}