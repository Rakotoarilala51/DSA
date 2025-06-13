#include<bits/stdc++.h>
using namespace std;
vector<int> extendGcd(int a, int b){
    if(b==0){
        return {1,0};
    }
    vector<int> result=extendGcd(b, a%b);
    int smalx= result[0];
    int smaly=result[1];

    int x=smaly;
    int y=smalx - (a/b)*smaly;
    return {x,y};
}
int main(){
    vector<int> result=extendGcd(18,12);
    cout<<result[0]<<" "<<result[1];
}
