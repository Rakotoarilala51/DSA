#include<bits/stdc++.h>
using namespace std;

bool solve(string s){
    unordered_map<string, int> sets;
    stringstream ss(s);
    int quantity;
    string color;
    while(ss>>quantity>>color){
        if((!color.empty() && (color.back()==',' || color.back()==';'))){
            color.pop_back();
        }
        sets[color]+=quantity;
    }
    return (sets["red"]<=12 && sets["green"]<=13 && sets["blue"]<=14);
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
        if(solve(input)) sum+=i;
        i++;
    }
    cout<<sum;
    return 0;
}