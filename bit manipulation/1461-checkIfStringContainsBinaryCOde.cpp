#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        if((n-k+1)<(1<<k)) return false;
        unordered_set<string> substringSet;
        for(int i=0; i<=(n-k); i++){
            string bin = s.substr(i, k);
            cout<<bin.length()<<endl;
            substringSet.insert(bin);
        }
        return substringSet.size()==(1<<k);
    }
};
int main(){
    Solution solution;
    string s="000011010111011001001111111001000100100100010100101100001101101101110001100100101111100111001001111001001010111010010101101001001110011100110101001001001000000110101001010011101100110110100010000";
    cout<<solution.hasAllCodes(s,7);
}