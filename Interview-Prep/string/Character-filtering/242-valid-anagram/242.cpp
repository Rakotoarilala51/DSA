#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
    public:
    bool isAnagram(string s, string t){
        unordered_map<char, int> cnt;
        for(char c: s){
            cnt[c]++;
        }
        for(char c:t){
            if(!cnt.count(c)) return false;
            cnt[c]--;
            if(cnt[c]==0) cnt.erase(c);
        }
        return cnt.size()==0;
    }
};
int main(){
    Solution solution;
    string s= "anagram", t = "nagarama";
    cout<<solution.isAnagram(s,t);
}