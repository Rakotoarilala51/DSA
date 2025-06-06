#include<bits/stdc++.h>
using namespace std;
int solve(){
    string input, number="";
    cin>>input;
    int left=0, right=input.length()-1;
    while(left<input.size() && !isdigit(input[left])){
        left++;
    }
    while(right>=0 && !isdigit(input[right])){
        right--;
    }
    if(left<input.size()) number+=input[left], number+=input[right];
    return stoi(number);
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, sum=0;
    cin>>t;
    while(t--){
        sum+=solve();
    }
    cout<<sum<<endl;
   
}