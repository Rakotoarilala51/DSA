#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        unordered_set<int> s(target.begin(), target.end());
        int index=0;
        for(int i=1; i<=n; i++){
            result.push_back("push");
            if(s.find(i)==s.end()) result.push_back("pop");
        }
        return result;
    }
};
int main(){
    Solution solution;
    vector<int> target = {1,3};
    int n = 3;
    vector<string> result = solution.buildArray(target, n);
    for(string s:result){
        cout<<s<<" ";
    }
}