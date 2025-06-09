#include<bits/stdc++.h>
using namespace std;
int solve(string s){
    unordered_map<string, int> sets{
        {"red", 0}, 
        {"green", 0}, 
        {"blue", 0},
    };
    int maxProduct=1;
    stringstream ss(s);
    string token;
    while(getline(ss, token, ';')){
        stringstream sss(token);
        int quantity;
        string color;
        while(sss>>quantity>>color){
            if(!color.empty() && color.back()==',') color.pop_back();
            sets[color]=max(sets[color], quantity);
        }
    }
    int red = sets["red"];
    int green = sets["green"];
    int blue = sets["blue"];

    return red * green * blue;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string line;
    int sum=33293;
    while(getline(cin, line)){
        string input = line.substr(8);
        sum+=solve(input);
    }
     cout<<sum;
}
