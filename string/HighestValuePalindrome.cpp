#include<bits/stdc++.h>
using namespace std;
string highestValuePalindrome(string s, int n, int k){
    string result=s;
    int left=0, right=n-1;
    vector<bool> changed(n, false);
    while(left<right){
        if(result[left]!=result[right]){
            char x=(max(result[left]-'0', result[right]-'0'))+'0';
            result[left]=x;
            result[right]=x;
            changed[left]=changed[right]=true;
            k--;
        }
            left++;
            right--;
    }
    if(k<0) return "-1";
    left=0, right=n-1;
while (left <= right && k > 0) {
        if (left == right) {
            if (result[left] != '9' && k >= 1) {
                result[left] = '9';
                k--;
            }
        } else {
            if (result[left] != '9') {
                if (changed[left] && k >= 1) {
                    result[left] = result[right] = '9';
                    k--;
                }
                else if (!changed[left] && k >= 2) {
                    result[left] = result[right] = '9';
                    k -= 2;
                }
            }
        }
        left++;
        right--;
    }
    return result;
}
int main(){
      int n = 6, k = 3;
    string s = "092282";
    cout<<highestValuePalindrome(s, n, k);
}