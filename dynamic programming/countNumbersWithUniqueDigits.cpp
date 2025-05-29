#include<iostream>
using namespace std;

class Solution{
    public:
        int countNumbersWithUniqueDigits(int n){
            if(n==0) return 1;
            return countNumbersWithUniqueDigits(n-1)+(9*fact(9)/fact(10-n));
        }
        int fact(int n){
        if(n==0) return 1;
        return n*fact(n-1);
        }
};
int main(){
    Solution solution;
    cout<<solution.countNumbersWithUniqueDigits(0);
}