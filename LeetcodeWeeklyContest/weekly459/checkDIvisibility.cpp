#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum =0;
        int product = 1;
        int temp = n;
        while(temp){
            int lastDigit = temp%10;
            sum+=lastDigit;
            product*=lastDigit;
            temp/=10;
        }
        return !(n%(sum+product));
    }
};

int main(){
    Solution solution;
    cout<<solution.checkDivisibility(21);
}