#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
   vector<pair<string, int>> final;
    while(t--){
        string s;
        int note;
        cin>>s>>note;
        final.push_back({s, note});
    }
    
    sort(final.begin(), final.end(), [](auto&a, auto&b){a.second>b.second});
    for(auto list: final){
        cout<<list.first<<" "<<list.second<<endl;
    }
}