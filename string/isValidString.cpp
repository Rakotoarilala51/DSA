#include<bits/stdc++.h>
using namespace std;
string isValid(string s){
    unordered_map<char, int> frequncy;
    unordered_map<char, int> freqCount;
    for(char c: s) frequncy[c]++;
    for(auto& f: frequncy){
        freqCount[f.second]++;
    }
    if(freqCount.size()==1) return "YES";
    if(freqCount.size()==2){
        auto it=freqCount.begin();
        int f1=it->first,c1=it->second;
        ++it;
        int f2=it->first,c2=it->second;
        if((f1==1 && c1==1) || (f2==1 && c2==1)) return "YES";
        if(abs(f1-f2)==1 && (f1>f2 && c1==1) || (f2>f1 && c2==1)) return "YES";

    }
    return "NO";
}
int main(){
    string s="aabbcd";
    cout<<isValid(s);
}