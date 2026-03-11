#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int temp=x;
        long long ans=0;
        while(temp){
            ans=ans*10+temp%10;
            temp/=10;
        }
        if(ans>INT32_MAX or int(ans)<-INT32_MAX) return 0;
        return int(ans);
    }
};
int main(){
    Solution solution;
    cout<<solution.reverse(-4312);
}