#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countWord(string s){
        istringstream stream(s);
        string word;
        int count =0;
        while(stream>>word){
            count++;
        }
        return count;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> mapCount;
        for(int i=0; i<messages.size(); i++){
            string message = messages[i];
            int wordCount = countWord(message);
            string sender = senders[i];
            mapCount[sender]+=wordCount;
        }
        vector<pair<string, int>> senderMessageCount(mapCount.begin(), mapCount.end());
        sort(senderMessageCount.begin(), senderMessageCount.end(), [](const auto& a, const auto& b){
            if(a.second==b.second) return lexicographical_compare(a.first.begin(), a.first.end(), b.first.begin(), b.first.end());
            return a.second>b.second;
        });
        string answer = senderMessageCount[0].first;
        return answer;
    }
};
int main(){
    Solution solution;
    cout<<solution.countWord("Hello word letsy my negga")<<endl;
}