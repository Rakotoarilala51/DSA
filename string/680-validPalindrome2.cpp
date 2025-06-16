#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(string& s , int l, int r){
        if(l>=r) return true;
        return (s[l]==s[r] && isPalindrome(s, l+1, r-1));
    }
    bool validPalindrome(string s) {
        if(s.size()<=2) return true;
        int left=0, right=s.size()-1;
        while(left<=right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else{
                return isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1);
            }
        }
        return true;
    }
};
int main(){
    Solution solution;
    cout<<solution.validPalindrome("eceec");
}