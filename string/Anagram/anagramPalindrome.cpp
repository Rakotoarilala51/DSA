#include<bits/stdc++.h>
using namespace std;
int anagramPalindrom(string s){
    unordered_map<char, int> frequency;
    int oddCount=0;
    for(char c:s) frequency[c]++;
    for(auto f: frequency){
        if(f.second&1) oddCount++;
    }
       return oddCount <= 1 ? 1 : 0;
}
int main(){
    string s="geeksooogeeks";
    cout<<anagramPalindrom(s);
}