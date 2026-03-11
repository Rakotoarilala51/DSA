#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> nums;
void dp(int n){
    if(n==1){
        cout<<1<<endl;
        return;
    }
    cout<<n<<" ";
    if(!(n&1)) dp(n>>1);
    else dp((3*n)+1);
}
int32_t main(){
    int n;
    cin>>n;
    dp(n);
}