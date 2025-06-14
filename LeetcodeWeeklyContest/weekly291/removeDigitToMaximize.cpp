#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans="0";
        for(int i=0; i<number.size(); i++){
            if(number[i]==digit){
                string substr1=number.substr(0, i);
                string substr2=number.substr(i+1);
                string concat=substr1+substr2;
                if(concat>ans) ans=concat;
            }
        }
        return ans;
    }
};
int main(){
    Solution solution;
    cout<<solution.removeDigit("551",'5');
}