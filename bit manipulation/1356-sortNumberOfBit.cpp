#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSetBits(int n){
        int count =0;
        while(n){
            if(n&1) count++;
            n>>=1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [this](const auto& a, const auto& b){
        if(__builtin_popcount(a)==__builtin_popcount(b)) return a<b;
        return __builtin_popcount(a)<__builtin_popcount(b);
    });
        return arr;
    }
};
int main(){
    Solution solution;
    vector<int> arr= {0,1,2,3,4,5,6,7,8};
    solution.sortByBits(arr);
    for(int x: arr){
        cout<<x<<",";
    }
}