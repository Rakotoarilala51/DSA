#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countCollisions(string directions) {
        string stack;
        int sum=0;
        for(int i=0; i<directions.size(); i++){
            if(directions[i]!='S') sum++;
        }
        int left=0;
        while(directions[left]=='L' and left<directions.size()){
            sum--;
            left++;
        }
        int right=directions.size()-1;
        while(directions[right]=='R' and right>0){
            sum--;
            right--;
        }
        return sum;
    }
};
int main(){
    Solution solution;
    cout<<solution.countCollisions("SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR");
}