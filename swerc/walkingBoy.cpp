#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    a.insert(a.begin(), 0);
    a.push_back(1440);
    int walkCount = 0;
    for(int i=0;i<a.size(); i++){
        int gap = a[i] - a[i - 1];
        walkCount += gap / 120;
    }
    cout << (walkCount >= 2 ? "YES" : "NO") << '\n';

};
int main(){
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}