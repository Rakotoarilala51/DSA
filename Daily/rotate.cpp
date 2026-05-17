#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt","r", stdin);
    freopen("testcase.txt","w", stdout);
    
    srand(time(0));
    
    int t = rand() % 10 + 1;
    cout << t << "\n";
    
    for(int i = 0; i < t; i++){
        int len = rand() % 10 + 1;
        string word1 = "", word2 = "";
        for(int j = 0; j < len; j++){
            word1 += (char)('a' + rand() % 26);
            word2 += (char)('a' + rand() % 26);
        }
        cout << word1 << " " << word2 << "\n";
    }
    
    return 0;
}