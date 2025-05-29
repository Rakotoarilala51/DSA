#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
int dp_prime[N];
vector<int> divisor(int n){
    vector<int> div;
    for(int i=2;i*i<n; i++){
        if(n%i==0){
            div.push_back(i);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) div.push_back(n);
    return div;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    for(int i=0; i<n; i++){
        vector<int> divPrime = divisor(a[i]);
        int best_ending=0;
        for(auto x: divPrime){
            best_ending = max(dp_prime[x], best_ending);
            dp_prime[x]=best_ending+1;
        }
    }
    cout<<*max_element(dp_prime, dp_prime+N);

}