#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string generateTag(string caption) {
        string result="#";
        stringstream ss(caption);
        string token;
        while(ss>>token){
            string lower;
            if(result=="#"){
                transform(token.begin(), token.end(),back_inserter(lower),::tolower);
                result+=lower;
            }
            else{
                transform(token.begin(), token.end(),back_inserter(lower),::tolower);
                lower[0]=toupper(lower[0]);
                result+=lower;
            }
        }
        return result.substr(0,100);
    }
};
int main(){
    Solution solution;
    cout<<solution.generateTag("Leetcode daily streak achieved");
}