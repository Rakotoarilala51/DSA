#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result="",s="";
        int n=nums.size();
        unordered_set<string> bin;
        for(string num: nums){
            bin.insert(num);
        }
        backtrack(n, 0,s,bin, result);
        return result;
        }
        void backtrack(int n, int i, string& output, unordered_set<string>& bin, string& result){
            if(!result.empty()) return;
            if(i==n){
                
                if(bin.find(output)==bin.end()){
                    result=output;
                    return;
                }
                
              return ;
            }
            output+='0';
            backtrack(n, i+1, output, bin, result);
            output.pop_back();
            output+='1';
            backtrack(n, i+1, output, bin, result);
            output.pop_back();
    
}
        
};

int main(){
    Solution solution;
    vector<string> nums={"010000111000010","101110001011010","011001100110100","100111001111001","000011010001101","101110110110111","011001111010101","100011100101110","110011000101001","110111100101011","100010110101100","111111110111111","101000101001101","011001001000101","110001011001101"};
    cout<<solution.findDifferentBinaryString(nums);
}