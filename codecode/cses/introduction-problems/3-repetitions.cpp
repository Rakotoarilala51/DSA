#include<bits/stdc++.h>
#define int long long
using namespace std;
int longestRepetion(string& s){
    int maximum=INT_MIN;
    int left=0, right=0;
    for(right; right<=s.size(); right++){
        
        while(s[right]!=s[left]){
            left=right;
        }
        maximum=max(right-left+1, maximum);
    }
    return maximum;
}
int32_t main(){
    string s;
    cin>>s;
    cout<<longestRepetion(s)<<endl;
}