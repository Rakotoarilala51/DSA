#include<iostream>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int res=0;
        int sum=0;
        int left=0;
        int right=0;
        while(right<s.size()){
          
            if(isVowel(s[right])) sum++;
            
            if(right>=k-1){
                res=max(res, sum);
                
                if(isVowel(s[left])){
                    sum--;
                    
                }
                left++;
            }
            right++;
        }
        return res;
    }
    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
};
int main(){
    string s="abciiidef";
    Solution solution;
    cout<<solution.maxVowels(s,3);
}