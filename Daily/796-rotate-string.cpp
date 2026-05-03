#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        if(s==goal) return true;
        vector<int> startCandidate;
        for(int i=0; i<goal.size(); i++){
            if(goal[i]==s[0]){
                string part=goal.substr(i, goal.size());
                string anotherPart=goal.substr(0,i);
                if(s==(part+anotherPart)) return true;
            }
        }
        return false;
    }
};
int main(){
    Solution solution;
    string s = "abcde", goal = "abced";
    cout<<solution.rotateString(s,goal);
}