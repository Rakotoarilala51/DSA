#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseByType(string s) {
        int left=0, right=s.size()-1;
        while(left<right){
            if(isalpha(s[left]) and isalpha(s[right])){
                swap(s[left], s[right]);
                left++;
                right--;
            }
            if(!isalpha(s[left])) left++;
            if(!isalpha(s[right])) right--;
        }
        left=0;
        right=s.size()-1;
        while(left<right){
            if(!isalpha(s[left]) and !isalpha(s[right])){
                swap(s[left], s[right]);
                left++;
                right--;
            }
            if(isalpha(s[left])) left++;
            if(isalpha(s[right])) right--;
        }
        
        return s;
    }
};

int main(){
    Solution solution;
    string s;
    cin>>s;
    cout<<solution.reverseByType(s);
}