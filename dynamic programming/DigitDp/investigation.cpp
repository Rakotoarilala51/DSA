#include<bits/stdc++.h>
using namespace std;
string n;
int a,b, k;
int dp(int index, bool last, int sum_mod, int sum_dig_mod){
    if(index==n.size()){
        if(sum_mod==0 && sum_dig_mod==0){
            return 1;
        }
        return 0;
    }
    int till = last?n[index]-'0':9;
    int ans=0;
    for(int digit=0; digit<=till; digit++){
        ans+=dp(index+1, last && digit==till, ((sum_mod*10)+digit)%k, (sum_dig_mod+digit)%k);
    }
    return ans;
}
int solve(int _n){
    n=to_string(_n);
    return dp(0, 1,0,0);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b>>k;
        cout<<solve(b)-solve(a-1)<<endl;
    }
    
    return 0;
}