#include<bits/stdc++.h>
using namespace std;
string s;
void dp(string ans,int index, bool last){
    if(index==s.size()){
        cout<<ans<<endl;
        return;
    }
    int till = (last?s[index]-'0': 9);
    for(int i=0; i<=till; i++){
        dp(ans+to_string(i), index+1, last && (i==till));
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>s;
    dp("", 0, true);
    return 0;
}