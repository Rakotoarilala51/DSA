#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        for(string word: words){
            map[word]++;
        }
        vector<pair<string, int>> frequency(map.begin(), map.end());
        nth_element(
            frequency.begin(),
            frequency.begin() + frequency.size() - k,
            frequency.end(),
            [](const auto& a, const auto& b){
                return a.second < b.second && ;
            }
        );
        sort(frequency.begin()+k-1, frequency.end(), [](const auto& a, const auto&b){
            if(a.second==b.second) return !lexicographical_compare(a.first.begin(), a.first.end(), b.first.begin(), b.first.end());
            return a.second<b.second;
        });
        vector<string> result;
        for(int i=(int)frequency.size()-1; i>=(int)frequency.size()-k; i--){
            auto it = frequency[i];
            cout<<it.first<<endl;
            result.push_back(it.first);
        }
        return result;
    }
};
int main(){
    Solution solution;
    vector<string> s={"aaa", "aa", "a"};
    string a= "a";
    string b= "aa";
    cout<<lexicographical_compare(a.begin(), a.end(), b.begin(), b.end())<<endl;
    solution.topKFrequent(s, 2);
}