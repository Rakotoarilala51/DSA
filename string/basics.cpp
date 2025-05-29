#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s;
    vector<string> ss;
    int t=5;
    
    while(t--){
        getline(cin, s);
        ss.push_back(s);
    }
    for(string x :ss){
        cout<<x<<endl;
    }

    return 0;
}