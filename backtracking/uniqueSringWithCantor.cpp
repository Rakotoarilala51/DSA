#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result;
        
        for (int i = 0; i < n; ++i) {
            
            result += (nums[i][i] == '0') ? '1' : '0';
        }

        return result;
    }
};
int main(){
        Solution solution;
    vector<string> nums={"010000111000010","101110001011010","011001100110100","100111001111001","000011010001101","101110110110111","011001111010101","100011100101110","110011000101001","110111100101011","100010110101100","111111110111111","101000101001101","011001001000101","110001011001101"};
    cout<<solution.findDifferentBinaryString(nums);
}