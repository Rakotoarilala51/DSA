#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
vector<int> extendedGcd(int a, int b){
    if(b==0) return {1,0,a};
    vector<int> result = extendedGcd(b, a%b);
    int smallX= result[0];
    int smallY= result[1];
    int gcd= result[2];

    int x=smallY;
    int y=smallX-(a/b)*smallY;
    return {x,y, gcd};
}
int main(){
    cout<<gcd(5,10);
}