class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        
        string ans = "";
        unordered_map<string, int> m;

        for(int i=0; i<senders.size(); i++){
            int count= 1;
            for(char c : messages[i]) if(c==' ') count++;

            m[senders[i]] += count;
        }

        int freq = 0;
        for(auto &x : m){
            string x1 = x.first;
            int x2 = x.second;

            if(x2 > freq){
                ans = x1;
                freq = x2;
            }
            else if(x2 == freq){
                if(x1 > ans){
                    ans = x1;
                    freq = x2;
                }
            }
        }

        return ans;
    }
};